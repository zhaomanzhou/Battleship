//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_CONTROLLER_H
#define BATTLESHIP_CONTROLLER_H
#include <memory>
#include <string>

#include "GameAttributes.h"
#include "Player.h"
#include "Model.h"

namespace BattleShip {
class Controller {
public:
  Controller();
  void setupGame(const std::string& GameConfigurationFile, int seed);
  void setupGame(const std::string& GameConfigurationFile);
  void playGame();

protected:
    GameAttributes attributes;
    Player *player1;
    Player *player2;
    Model model;



};
}

#endif //BATTLESHIP_CONTROLLER_H
