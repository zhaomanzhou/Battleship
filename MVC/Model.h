//
// Created by zmz on 19-3-21.
//

#ifndef BATTLESHIP_MODEL_H
#define BATTLESHIP_MODEL_H

#include <iostream>
#include <Player.h>
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "GameAttributes.h"

namespace BattleShip {
    class Model {
    public:
        void init();
        Player* getFirstPlayer();
        Player* getSecondPlayer();

    private:
        void prompt();
        Player* player1;
        Player* player2;
        GameAttributes gameAttributes;
        void initPlayer(Player* player, int playerNum);
    public:
        void setGameAttributes(const GameAttributes &gameAttributes);
    };
}


#endif //BATTLESHIP_MODEL_H
