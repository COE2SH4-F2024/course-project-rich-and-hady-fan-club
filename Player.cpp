#include "Player.h"
#include "GameMechs.h"

//default constructor
Player::Player(GameMechs* thisGMRef)
{
    //taking in GameMechs pointers
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    //making new objPosArrayList
    playerPosList = new objPosArrayList();

    //snake head start in middle of the game board
    objPos headPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, playerPosList->getElement(0).getSymbol());

    //putting head into array list (at front)
    playerPosList->insertHead(headPos);
}

//deconstructor
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

//this method takes in the user input (WASD) and assigns the corresponding direction 
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
    objPos tempHead(playerPosList->getHeadElement().getObjPos().pos->x, playerPosList->getHeadElement().getObjPos().pos->y, playerPosList->getElement(0).getSymbol());
    
    //head moves position according to the specified direction from the user input
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

    playerPosList->insertHead(tempHead);

    // ITERATION 3 - Add what happens if food is eaten (do not remove snake tail if food eaten)
    // If head is at food (there is a collision) after the movement (switch case)
    if(playerPosList->getHeadElement().getObjPos().pos->x == mainGameMechsRef->getFoodPos().getObjPos().pos->x && playerPosList->getHeadElement().getObjPos().pos->y == mainGameMechsRef->getFoodPos().getObjPos().pos->y){
        
        //generate new food
        mainGameMechsRef->generateFood(playerPosList);
        // Add point scoring
        mainGameMechsRef->incrementScore();
    }
    else
    {
        //no food collision, remove tail for snake body movement
        playerPosList->removeTail();
    }

    // check if the snake collided with itself
    for (int i = 1; i < playerPosList->getSize(); i++){
        objPos bodyPos = playerPosList->getElement(i);
        // check if the body is overlapping anywhere to see if they have lost the game
        if (tempHead.pos->x == bodyPos.pos->x && tempHead.pos->y == bodyPos.pos->y){
            //set flags to true to end game
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

}

// More methods to be added
