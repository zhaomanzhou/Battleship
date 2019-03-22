//
// Created by zmz on 19-3-21.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include "Board.h"
#include <string>

namespace BattleShip {

    class Player {
    public:
        Player(int numRows, int numCols);

        Board board;
    private:
        std::string name;
    public:
        const std::string &getName() const;
        void printVisibleBoard();
        void setName(const std::string &name);
    };

}
#endif //BATTLESHIP_PLAYER_H
