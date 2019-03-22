//
// Created by zmz on 19-3-21.
//

#include "Model.h"
#include "GameAttributes.h"
#include <string>
#include <limits>


void BattleShip::Model::init() {
    int numRows = gameAttributes.getNumRows();
    int numCols = gameAttributes.getNumCols();
    int choice = -1;
    do{
        prompt();
        std::cin>>choice;
    }while (choice < 1 || choice > 3);

    switch (choice)
    {
        case 1: {
            player1 = new HumanPlayer(numRows, numCols);
            initPlayer(player1, 1);
            player2 = new HumanPlayer(numRows, numCols);
            initPlayer(player1, 2);
            break;
        }
        case 2:{
            player1 = new HumanPlayer(numRows, numCols);
            initPlayer(player1, 1);
            player2 = new AiPlayer(numRows, numCols);
            break;
        }
        case 3:{
            player1 = new AiPlayer(numRows, numCols);
            player2 = new AiPlayer(numRows, numCols);
            break;
        }
    }



}

void BattleShip::Model::prompt() {
    std::cout<<"What type of game do you want to play?\n"
               "1. Human vs Human\n"
               "2. Human vs AI\n"
               "3. AI vs AI\n"
               "Your choice: ";
}

BattleShip::Player *BattleShip::Model::getFirstPlayer() {
    return player1;
}

BattleShip::Player *BattleShip::Model::getSecondPlayer() {
    return player2;
}

void BattleShip::Model::setGameAttributes(const BattleShip::GameAttributes &gameAttributes) {
    this->gameAttributes = gameAttributes;

}

void BattleShip::Model::initPlayer(BattleShip::Player *player, int playerNum) {
    std::cout<<"Player "<<playerNum<<" please enter your name: ";
    std::string name;
    std::cin>>name;
    player->setName(name);
    player1->printVisibleBoard();
    const std::map<char, int> &map = gameAttributes.getShipAttributes();
    auto it= map.begin();
    while (it != map.end())
    {

        char direction;
        do{
            std::cout<<name<<", do you want to place "<<it->first<<" horizontally or vertically?\n"
                             "Enter h for horizontal or v for vertical\n"
                             "Your choice: ";
            std::cin>>direction;
        }while (direction != 'v' && direction != 'h');
        int row, col;

        std::cout << name
                  << ", enter the row and column you want to place "<<it->first<<", which is 3 long, at with a space in between row and col: ";
        while (!(std::cin>>row && std::cin>>col))
        {
            std::cout << name
                      << ", enter the row and column you want to place "<<it->first<<", which is 3 long, at with a space in between row and col: ";
            //flush the buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        ShipPlacement placement(row, col, direction, it->second);
        if(player->board.canPlaceShipAt(placement))
        {
            player->board.AddShip(it->first, placement);
            it++;
        }
        player->printVisibleBoard();




    }

}




