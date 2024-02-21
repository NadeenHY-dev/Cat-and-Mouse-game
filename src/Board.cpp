#include "Board.h"
#include<string>
//#include"Wall.h"
//
#include"Wall.h"
//#include"Door.h"
//#include"Gift.h"
//#include"Key.h"
//#include"Cheese.h"
//class Wall;

Board::Board()
{
}

Board::~Board()
{
}

void Board::readToFile(size_t i)
{
    std::string filename = "Level" + std::to_string(i) + ".txt";
    auto myFile = std::ifstream(filename);
    if (!myFile.is_open()) {
        std::cerr << "The file cannot open \n";
        exit(EXIT_FAILURE);
    }
    size_t row, col;
    myFile >> row >> col;
    m_board.resize(row);
    char c;
    for (size_t i = 0; i < row; i++) {
        m_board.at(i).resize(col);  // we have to check
        for (size_t j = 0; j < col; j++) {
            myFile >> c;
            insertIcon(c,i,j);
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


void Board::insertIcon(const char c,size_t i ,size_t j)
{
    switch (c)
    {
    case '#':
        //m_board.at(i).at(j) = std::make_unique<Wall>();
        break;
    case '%':
       // m_board.at(i).at(j) = std::make_unique<Mouse>();// ?
        break;
    case '$':
       // m_board.at(i).at(j) = std::make_unique<Gift>();
        break;
    case 'F':
       // m_board.at(i).at(j) = std::make_unique<Key>();
        break;
    case '^':
       // m_board.at(i).at(j) = std::make_unique<Cat>();// ?
        break;
    case '*':
       // m_board.at(i).at(j) = std::make_unique<Cheese>();
        break;
    case 'D':
        //m_board.at(i).at(j) = std::make_unique<Door>();
        break;
    default:
        break;
    }
}

