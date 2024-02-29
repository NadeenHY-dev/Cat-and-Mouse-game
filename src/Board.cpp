#include "Board.h"



Board::Board() : m_maxCol(0), m_maxRow(0)
{
    setBackGround();
}

Board::~Board()
{
}


void Board::readToFile(const std::string level_name, Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cat
                      ,std::vector<std::unique_ptr<StaticObject>>& staticObjects)
{
    //std::string filename = "Level" + std::to_string(level) + ".txt";
    auto myFile = std::ifstream( level_name);
    if (!myFile.is_open()) {
        std::cerr << "The file cannot open \n";
        exit(EXIT_FAILURE);
    }
    myFile >> m_maxRow >> m_maxCol;
    m_board.resize(m_maxRow);

    char c;
    for (size_t i = 0; i < m_maxRow; i++) {
        myFile.get();
        m_board.at(i).resize(m_maxCol);  // we have to check
        for (size_t j = 0; j < m_maxCol; j++) {
            c = static_cast<char>(myFile.get());

            insertIcon(c,i,j,mouse , cat,staticObjects);
        }
    }
    myFile.seekg(0, std::ios::beg);
    myFile.close();
}

void Board::printer(sf::RenderWindow& window)
{
    // Draw the background first
    window.draw(backgroundSprite);

    for (size_t i = 0; i < m_maxRow; i++) {
        for (size_t j = 0; j < m_maxCol; j++) {
            if (m_board.at(i).at(j) != nullptr)
                m_board.at(i).at(j)->draw(window);
        }
    }
}

//######
//#*#**#
//# D * *# 
//#*F**#
//#*$%^#
//######


void Board::insertIcon(const char c,size_t i ,size_t j, Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cat
                     , std::vector<std::unique_ptr<StaticObject>>& staticObjects)
{
    switch (c)
    {
    case '#':                                        // Size = 60 ;
        m_board.at(i).at(j) = std::make_unique<Wall>(sf::Vector2f(j * SIZE, i * SIZE));
        staticObjects.push_back(std::make_unique<Wall>(sf::Vector2f(j * SIZE, i * SIZE)));
        break;
    case '%':
        mouse.setPosition(sf::Vector2f(j * SIZE, i * SIZE));
        break;
    case '$':
        m_board.at(i).at(j) = std::make_unique<Gift>(sf::Vector2f(j * SIZE, i * SIZE));
        staticObjects.push_back(std::make_unique<Gift>(sf::Vector2f(j * SIZE, i * SIZE)));
        break;
    case 'F':
        m_board.at(i).at(j) = std::make_unique<Key>(sf::Vector2f(j * SIZE, i * SIZE));
        staticObjects.push_back(std::make_unique<Key>(sf::Vector2f(j * SIZE, i * SIZE)));
        break;
    case '^':
        cat.push_back(std::make_unique<Cat>(sf::Vector2f(j * SIZE, i * SIZE)));
        break;
    case '*':
        m_board.at(i).at(j) = std::make_unique<Cheese>(sf::Vector2f(j * SIZE, i * SIZE));
        staticObjects.push_back(std::make_unique<Cheese>(sf::Vector2f(j * SIZE, i * SIZE)));
        break;
    case 'D':
        m_board.at(i).at(j) = std::make_unique<Door>(sf::Vector2f(j * SIZE, i * SIZE));
        staticObjects.push_back(std::make_unique<Door>(sf::Vector2f(j * SIZE, i * SIZE)));
        break;
    default:
        break;
    }
}

void Board::setBackGround()
{
    if (!backgroundTexture.loadFromFile("boardBackGround.png")) {
        std::cerr << "Failed to load background image\n";
    }
    else {
        backgroundSprite.setTexture(backgroundTexture);

        // Assuming you have the window size or desired background size
        float desiredWidth = 800; // Width of the window or board
        float desiredHeight = 600; // Height of the window or board, adjust this to how far down you want the image to go

        // Get the actual size of the texture
        sf::Vector2u textureSize = backgroundTexture.getSize();

        // Calculate the scale factors
        float scaleX = desiredWidth / static_cast<float>(textureSize.x);
        float scaleY = desiredHeight / static_cast<float>(textureSize.y);

        // Set the scale of the sprite
        backgroundSprite.setScale(scaleX, scaleY);
    }
}

bool Board::notInRange(sf::Vector2f position) const {
    return position.x >= 0 && position.x < (m_maxCol-1) * SIZE  &&
        position.y >= 0 && position.y < (m_maxRow-1) * SIZE ;
}
