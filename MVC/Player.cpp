//
// Created by zmz on 19-3-21.
//

#include <iostream>
#include "Player.h"


BattleShip::Player::Player(int numRows, int numCols) :board(numRows, numCols){

}

const std::string &BattleShip::Player::getName() const {
    return name;
}

void BattleShip::Player::setName(const std::string &name) {
    Player::name = name;
}

void BattleShip::Player::printVisibleBoard() {
    const std::vector<std::string> &v = board.getVisibleVersion();
    for(std::string s: v)
    {
        std::cout<<s<<std::endl;
    }

}
