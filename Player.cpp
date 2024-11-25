#include "Player.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef)
{
    //taking in GameMechs pointers
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    //making new objPosArrayList
    playerPosList = new objPosArrayList();

    //storing the position in the head element of the snake
    objPos headPos(mainGameMechsRef->getBoardSizeX()/2+1, mainGameMechsRef->getBoardSizeX()/2+1, '*');
    // more actions to be included

    //putting head into array list
    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
                myDir = DOWN;
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
        default:
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    //get all info about head element
    objPos tempHead(playerPosList->getHeadElement().getObjPos().pos->x, playerPosList->getHeadElement().getObjPos().pos->y, '*');
    
    //head moves position
    switch (myDir)
    {
    case UP:
        tempHead.pos->y--;

        //wrap around 
        if (tempHead.pos->y == 0){
            tempHead.pos->y = (mainGameMechsRef->getBoardSizeY() - 2);
        }
        break;
    case DOWN:
        tempHead.pos->y++;

        //wrap around 
        if (tempHead.pos->y == (mainGameMechsRef->getBoardSizeY() - 1)){
            tempHead.pos->y = 1;
        }
        break;
    case LEFT:
        tempHead.pos->x--;

        //wrap around 
        if (tempHead.pos->x == 0){
            tempHead.pos->x = (mainGameMechsRef->getBoardSizeX() - 2);
        }
        break;
    case RIGHT:
        tempHead.pos->x++;

        //wrap around 
        if (tempHead.pos->x == (mainGameMechsRef->getBoardSizeX() - 1)){
            tempHead.pos->x = 1;
        }
        break;
    default:
        break;
    }

    // ITERATION 3 - Add what happens if food is eaten (do not remove snake tail if food eaten)
    // If head is at food (collision) after the movement (switch case)
    if(playerPosList->getHeadElement().getObjPos().pos->x == mainGameMechsRef->getFoodPos().getObjPos().pos->x && playerPosList->getHeadElement().getObjPos().pos->y == mainGameMechsRef->getFoodPos().getObjPos().pos->y){
        
        //generate new food
        mainGameMechsRef->generateFood(playerPosList);
        // Add point scoring
        mainGameMechsRef->incrementScore();
    }
    else
    {
        playerPosList->removeTail();
    }

    // check if the snake collided with itself
    for (int i = 0; i < playerPosList->getSize(); i++){
        objPos bodyPos = playerPosList->getElement(i);
        // check if the body is overlapping anywhere to see if they have lost the game
        if (tempHead.pos->x == bodyPos.pos->x && tempHead.pos->y == bodyPos.pos->y){
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

}

// More methods to be added
