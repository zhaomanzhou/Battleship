//
// Created by mfbut on 3/10/2019.
//

#include <algorithm>
#include "ShipPlacement.h"

ShipPlacement::ShipPlacement() {

}

ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd)
{

}

void ShipPlacement::normalize() {

}

ShipPlacement::ShipPlacement(int rowStart, int colStart, char alignment, int length)
: rowStart(rowStart), colStart(colStart), length(length), alignment(alignment)
{

}
