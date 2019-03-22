//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"

BattleShip::Board::Board(int numRows, int numCols, char blankChar)
:blankChar(blankChar), numRows(numRows), numCols(numCols) {
    for (int i = 0; i < numRows; i++)
    {
        std::vector<Cell> *v = new std::vector<Cell>;
        for(int j = 0; j < numCols; j++)
        {
            Cell *x = new Cell(blankChar);
            v->push_back(*x);
        }
        boardState.push_back(*v);
    }
}

BattleShip::Board::Board(int numRows, int numCols)
:blankChar('*'), numRows(numRows), numCols(numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        std::vector<Cell> *v = new std::vector<Cell>;
        for(int j = 0; j < numCols; j++)
        {
            Cell *x = new Cell(blankChar);
            v->push_back(*x);
        }
        boardState.push_back(*v);
    }
}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
    if(shipPlacement.rowStart < 0 || shipPlacement.colStart < 0)
        return false;
    if(shipPlacement.alignment == 'v')
    {
        if(shipPlacement.rowStart + shipPlacement.length >= numRows)
            return false;
        for(int i = shipPlacement.rowStart; i < shipPlacement.length; i++)
        {
            if(boardState[i][shipPlacement.colStart].containsShip())
            {
                return false;
            }
        }
        return true;
    }


    if(shipPlacement.alignment == 'h')
    {
        if(shipPlacement.colStart + shipPlacement.length >= numCols)
            return false;
        for(int i = shipPlacement.colStart; i < shipPlacement.length; i++)
        {
            if(boardState[shipPlacement.rowStart][i].containsShip())
            {
                return false;
            }
        }
        return true;
    }

    return false;
}

int BattleShip::Board::getNumRows() const {
    return numRows;
}

int BattleShip::Board::getNumCols() const {
    return numCols;
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
    std::vector<std::string> v;
    std::string s;
    for (int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            s += boardState[i][j].getContentsIfHidden();
        }
        v.push_back(s);
        s = "";
    }
    return v;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
    std::vector<std::string> v;
    std::string s(" ");
    for(int i = 0; i < numCols; i++)
    {
        s += (" " + std::to_string(i));
    }
    v.push_back(s);
    s = "";
    for (int i = 0; i < numRows; i++)
    {
        s += std::to_string(i);
        for(int j = 0; j < numCols; j++)
        {
            s += " ";
            s +=  boardState[i][j].getContentsIfVisible();
        }
        v.push_back(s);
        s = "";
    }
    return v;
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
    if(shipPlacement.alignment == 'v')
    {

        for(int i = shipPlacement.rowStart; i < shipPlacement.length + shipPlacement.rowStart; i++)
        {
            boardState[i][shipPlacement.colStart].setContents(shipChar);

        }
    }


    if(shipPlacement.alignment == 'h')
    {

        for(int i = shipPlacement.colStart; i < shipPlacement.length + shipPlacement.colStart; i++)
        {
            boardState[shipPlacement.rowStart][i].setContents(shipChar);
        }
    }
}

bool BattleShip::Board::inBounds(int row, int col) const {
    return false;
}

BattleShip::Cell &BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}

const BattleShip::Cell &BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}

bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
    return false;
}

bool BattleShip::Board::between(int value, int low, int high) const {
    return false;
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const {
    return false;
}
