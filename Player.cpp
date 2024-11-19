#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructor - LEAVE EMPTY FOR NOW
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    // PPA3 input processing logic  
    switch(input)
    {
        case 'W':
        case 'w':
            if (myDir != UP && myDir != DOWN){
                myDir = UP;
            }
            break;
        case 'S':
        case 's':
            if (myDir != UP && myDir != DOWN){
                myDir = UP;
            }
            break;
        case 'A':
        case 'a':
            if (myDir != LEFT && myDir != RIGHT){
                myDir = LEFT;
            }
            break;
        case 'D':
        case 'd':
            if (myDir != LEFT && myDir != RIGHT){
                myDir = RIGHT;
            }
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added