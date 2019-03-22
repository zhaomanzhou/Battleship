//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker)
: contents(contents), hiddenMarker('*'),  hitMarker('X'), missMarker('0')
{
    firedAt = false;
}

BattleShip::Cell::Cell(char contents)
: contents(contents), hiddenMarker('*'),  hitMarker('X'), missMarker('0')
{
    firedAt = false;
}

char BattleShip::Cell::getContents() const {
    return contents;
}

void BattleShip::Cell::setContents(char contents) {
    this->contents = contents;
}

char BattleShip::Cell::getContentsIfHidden() const {
    //not fired
    if(!firedAt)
        return '*';

    //fired
    if(contents == '*')
        return missMarker;
    else
        return hitMarker;
}

char BattleShip::Cell::getContentsIfVisible() const {
    //not fired
    if(!firedAt)
        return contents;

    //fired
    if(contents == '*')
        return missMarker;
    else
        return hitMarker;
}

bool BattleShip::Cell::HasBeenFiredAt() const {
    return firedAt;
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    this->firedAt = hasBeenFiredAt;
}

bool BattleShip::Cell::containsShip() const {
    return contents != '*' ;
}
