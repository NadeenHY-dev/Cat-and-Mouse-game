#include "Board.h"



Board::Board() : m_maxCol(0) , m_maxRow(0)
{
}

Board::~Board()
{
}

void Board::readToFile(size_t level)
{
    std::string filename = "Level" + std::to_string(level) + ".txt";
    auto myFile = std::ifstream(filename);
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
            insertIcon(c,i,j);
        }
    }
    myFile.seekg(0, std::ios::beg);
    myFile.close();
}

void Board::printer(sf::RenderWindow& window)
{
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

void Board::insertIcon(const char c,size_t i ,size_t j)
{
    switch (c)
    {
    case '#':                                        // Size = 60 ;
        m_board.at(i).at(j) = std::make_unique<Wall>(sf::Vector2f(j * SIZE, i * SIZE));
        break;
    case '%':
        m_board.at(i).at(j) = std::make_unique<Mouse>(sf::Vector2f(j * SIZE, i * SIZE));// ?
        break;
    case '$':
        m_board.at(i).at(j) = std::make_unique<Gift>(sf::Vector2f(j * SIZE, i * SIZE));
        break;
    case 'F':
        m_board.at(i).at(j) = std::make_unique<Key>(sf::Vector2f(j * SIZE, i * SIZE));
        break;
    case '^':
        m_board.at(i).at(j) = std::make_unique<Cat>(sf::Vector2f(j * SIZE, i * SIZE));// ?
        break;
    case '*':
        m_board.at(i).at(j) = std::make_unique<Cheese>(sf::Vector2f(j * SIZE, i * SIZE));
        break;
    case 'D':
        m_board.at(i).at(j) = std::make_unique<Door>(sf::Vector2f(j * SIZE, i * SIZE));
        break;
    default:
        break;
    }
}

