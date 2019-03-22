//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include "Controller.h"


BattleShip::Controller::Controller(){

}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {
    attributes.parse(GameConfigurationFile);
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {
    attributes.parse(GameConfigurationFile);
    int a = 0;
    a++;
}


void BattleShip::Controller::playGame() {
    model.setGameAttributes(attributes);
    model.init();
}
