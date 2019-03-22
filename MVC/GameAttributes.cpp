//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include <iostream>
#include <fstream>
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes() {

}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols) {

}

void BattleShip::GameAttributes::parse(const std::string &GameConfigurationFile) {
    std::ifstream is(GameConfigurationFile);
    is>>numRows;
    is>>numCols;
    int numShip;
    char shipName;
    int shipLength;

    is>>numShip;
    for(int i = 0; i < numShip; i++)
    {
        is>>shipName;
        is>>shipLength;
        shipAttributes[shipName] = shipLength;
    }
    is.close();
}

BattleShip::GameAttributes::GameAttributes(const std::string &GameConfigurationFile) {
    std::ifstream is(GameConfigurationFile);
    is>>numRows;
    is>>numCols;
    int numShip;
    char shipName;
    int shipLength;

    is>>numShip;
    for(int i = 0; i < numShip; i++)
    {
        is>>shipName;
        is>>shipLength;
        shipAttributes[shipName] = shipLength;
    }
    is.close();
}

int BattleShip::GameAttributes::getNumRows() const {
    return this->numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
    this->numRows = numRows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
    this->numCols = numCols;
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
    const std::map<char, int, std::less<char>, std::allocator<std::pair<const char, int>>>::const_iterator &iterator = shipAttributes.find(ShipChar);
    if(iterator != shipAttributes.end())
    {
        return iterator->second;
    }
    return 0;
}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return shipAttributes;
}
