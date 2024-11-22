#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;

    //initialize the food object
    food.setObjPos(1, 1, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

    //food.setObjPos(-10, -10, 'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // Nothing on heap - LEAVE EMPTY FOR NOW
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsyncInput()
{
    if (MacUILib_hasChar() != 0){
        input = MacUILib_getChar();
    }

    if (input == 27)
    {
        setExitTrue();
    }
}

char GameMechs::getInput() 
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    //makes input null
    input = 0;
}

// More methods should be added here

//get from PPA3
void GameMechs::generateFood(objPos blockOff)
{
    //you only need to block off the player position for now... later will have to upgrade to iteration 3 (arrayList)
    bool done = false;

    while (done == false)
    {
        //randomly generated x and y coordinates for food
        int x, y;
        x = rand()%(boardSizeX-2) +1;
        y = rand()%(boardSizeY-2) +1;
        char sym = 'o';

        //set food coordinates if it isnt the player position coordinates
        if (x!= blockOff.pos->x && y != blockOff.pos->y)
        {
            done = true;
            food.setObjPos(x, y, sym);
        }
    }
}

objPos GameMechs::getFoodPos() const
{
    return food;
}

