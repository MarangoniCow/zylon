/***********************************************************
 *                      PIECE IMPLEMENTATION
 ***********************************************************/

// INTERNAL INCLUDES
#include "Piece.h"

// EXTERNAL INCLUDES
#include <string>
#include <iostream>
#include <vector>

// Initialise static variables
int Piece::Piece_count = 0;
std::vector<Piece*> Piece::Piece_instanceList;

/*******    GETTER METHODS    *******/
void Piece::updatePosition(BoardPosition newPos)
{
    // Check flag
    if(!m_hasMoved)
        m_hasMoved = 1;
    
    pos.updatePosition(newPos);
}


/***********************************************************
 *                      MOVE RANGES
 * 
 * All movement ranges are defined such that all movements in
 * a particular axis are sequentially defined. This allows 
 * methods in-built to Board to check all the movements in one
 * direction sequentially, saving a lot of hassle!
 * 
 ***********************************************************/
PositionQueue Pawn::moveRange()
{
    PositionQueue moveQueue;

    // WHITE = 0, BLACK = 1
    if(!col) {
        if(pos.validUpdate(0, 1)) moveQueue.push(pos.returnUpdate(0, 1));
        if(!m_hasMoved && pos.validUpdate(0, 2)) moveQueue.push(pos.returnUpdate(0, 2));
    }
    else {
        if(pos.validUpdate(0, -1)) moveQueue.push(pos.returnUpdate(0, -1));
        if(!m_hasMoved && pos.validUpdate(0, -2)) moveQueue.push(pos.returnUpdate(0, -2));
    }  
    return moveQueue;
}

PositionQueue Rook::moveRange()
{
    PositionQueue moveQueue;

    // Moving right
    int i = 1;
    while(pos.validUpdate(i, 0)) {
        moveQueue.push(pos.returnUpdate(i, 0));
        i++;
   }

    // Moving left
    i = -1;
    while(pos.validUpdate(i, 0)) {
        moveQueue.push(pos.returnUpdate(i, 0));
        i--;
    }

    // Moving forward
    int j = 1;
    while(pos.validUpdate(0, j)) {
        moveQueue.push(pos.returnUpdate(0, j));
        j++;
    }

    // Moving backward
    j = -1;
    while(pos.validUpdate(0, j)) {
        moveQueue.push(pos.returnUpdate(0, j));
        j--;
    }
    
    return moveQueue;
}

PositionQueue Knight::moveRange()
{
    PositionQueue moveQueue;
    
    // Binary permutations of {1,2,-1,-2} without repettition of 1s/2s.
    if(pos.validUpdate(1, 2)) moveQueue.push(pos.returnUpdate(1, 2));
    if(pos.validUpdate(2, 1)) moveQueue.push(pos.returnUpdate(2, 1));

    if(pos.validUpdate(-1, 2)) moveQueue.push(pos.returnUpdate(-1, 2));
    if(pos.validUpdate(-2, 1)) moveQueue.push(pos.returnUpdate(-2, 1));

    if(pos.validUpdate(1, -2)) moveQueue.push(pos.returnUpdate(1, -2));
    if(pos.validUpdate(2, -1)) moveQueue.push(pos.returnUpdate(2, -1));

    if(pos.validUpdate(-1, -2)) moveQueue.push(pos.returnUpdate(-1, -2));
    if(pos.validUpdate(-2, -1)) moveQueue.push(pos.returnUpdate(-2, -1));

    return moveQueue;
    
}

PositionQueue Bishop::moveRange()
{
    PositionQueue moveQueue;

    // Moving diagonal right
    int i = 1;
    int j = 1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i++;
        j++;
    }

    // Moving diagonal left
    i = -1;
    j = 1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i--;
        j++;
    }

    // Moving diagonal down-right
    i = 1;
    j = -1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i++;
        j--;
    }

    // Moving diagonal down-left
    i = -1;
    j = -1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i--;
        j--;
    }

    return moveQueue;
}

PositionQueue Queen::moveRange()
{
    PositionQueue moveQueue;

    // Moving right
    int i = 1;
    while(pos.validUpdate(i, 0)) {
        moveQueue.push(pos.returnUpdate(i, 0));
        i++;
    }

    // Moving left
    i = -1;
    while(pos.validUpdate(i, 0)) {
        moveQueue.push(pos.returnUpdate(i, 0));
        i--;
    }

    // Moving forward
    int j = 1;
    while(pos.validUpdate(0, j)) {
        moveQueue.push(pos.returnUpdate(0, j));
        j++;
    }

    // Moving backward
    j = -1;
    while(pos.validUpdate(0, j)) {
        moveQueue.push(pos.returnUpdate(0, j));
        j--;
    }

    // Moving diagonal right
    i = 1;
    j = 1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i++;
        j++;
    }

    // Moving diagonal left
    i = -1;
    j = 1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i--;
        j++;
    }

    // Moving diagonal down-right
    i = 1;
    j = -1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i++;
        j--;
    }

    // Moving diagonal down-left
    i = -1;
    j = -1;
    while(pos.validUpdate(i, j)) {
        moveQueue.push(pos.returnUpdate(i, j));
        i--;
        j--;
    }

    return moveQueue;
    
}

PositionQueue King::moveRange()
{
    PositionQueue moveQueue;

    // Permutations of {0, 1, -1}
    if(pos.validUpdate(1, 0))   moveQueue.push(pos.returnUpdate(1, 0));
    if(pos.validUpdate(1, 1))   moveQueue.push(pos.returnUpdate(1, 1));
    if(pos.validUpdate(0, 1))   moveQueue.push(pos.returnUpdate(0, 1));
    if(pos.validUpdate(-1, 0))  moveQueue.push(pos.returnUpdate(-1, 0));
    if(pos.validUpdate(-1, -1)) moveQueue.push(pos.returnUpdate(-1, -1));
    if(pos.validUpdate(0, -1))  moveQueue.push(pos.returnUpdate(0, -1));
    if(pos.validUpdate(1, -1))  moveQueue.push(pos.returnUpdate(1, -1));
    if(pos.validUpdate(-1, 1))  moveQueue.push(pos.returnUpdate(-1, 1));
    
    return moveQueue;
    
}