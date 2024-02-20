#include "Board.h"

void Board::readToFile(size_t i)
{
    std::string filename = "Level" + std::to_string(i) + ".txt";
    auto myFile = std::ifstream(filename);

    if (!myFile.is_open()) {
        std::cerr << "The file cannot open \n";
        exit(EXIT_FAILURE);
    }

    int width, height;
    myFile >> width >> height;

    for (int y = 0; y < height; ++y) {
        std::string line;
        myFile >> line;

        for (int x = 0; x < width; ++x) {
            char ch = line[x];
            Object* obj = nullptr;

            createObj(ch , obj);
            setObject(x, y, obj);
        }
    }
    //if (!m_board.empty()) {
    //    auto maxColSize = std::max_element(
    //        m_board.begin(), m_board.end(),
    //        [](const std::string& a, const std::string& b) {
    //            return a.length() < b.length();
    //        }
    //    )->length();
    //    m_maxCol = maxColSize;
    //}

    //// Set row size to the number of rows
    //m_maxRow = m_board.size();
    myFile.close();
}



void Board::setObject(int x, int y, Object* object) {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        m_objects[x][y] = std::make_unique<Object>(*object);
    }
}

void Board::render(sf::RenderWindow& window) {
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            Object* object = m_objects[x][y].get();
            if (object) {
                object->render(window);
            }
        }
    }
}


void Board::setTexture()
{
    m_wallTexture.loadFromFile("wall.png");
    m_doorTexture.loadFromFile("door.png");
    m_keyTexture.loadFromFile("key.png");
    m_giftTexture.loadFromFile("gift.png");
    m_catTexture.loadFromFile("cat.png");
    m_mouseTexture.loadFromFile("mouse.png");
}

void Board::createObj(char ch , Object*& obj)
{
    switch (ch) {
    case '#':
        obj = new Wall(m_wallTexture);
        break;
    case 'D':
        obj = new Door(m_doorTexture);
        break;
    case '*':
        obj = new Key(m_keyTexture);
        break;
    case '^':
        obj = new Gift(m_giftTexture);
        break;
    case 'C':
        obj = new Cat(m_catTexture);
        break;
    case '$':
        obj = new Mouse(m_mouseTexture);
        break;
    default:
        break;
    }
}
