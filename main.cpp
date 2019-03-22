#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char** argv) {
    BattleShip::Controller controller;

    std::string s = "/home/zmz/workspace/CLionProjects/MyBattleShip/GameConfigurations/3_3lenShips.txt";
    argv[1] = const_cast<char *>(s.c_str());
    if(argc == 2)
    {
        controller.setupGame(argv[1]);
    }else
    {
        controller.setupGame(argv[1], atoi(argv[2]));
    }

    controller.playGame();
    return 0;
}
