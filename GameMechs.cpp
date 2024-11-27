#include "GameMechs.h"
#include "MacUILib.h"

//default constructor
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
}

//constructor with custom game board size
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

}

//deconstructor
GameMechs::~GameMechs()
{
    // Nothing on heap - LEAVE EMPTY FOR NOW
}

//getter method for exit flag boolean
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

//getter method for lose flag boolean
bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

//takes in inputted char from keyboard and analyzes    
void GameMechs::collectAsyncInput()
{
    //only collect when the input is not null
    if (MacUILib_hasChar() != 0){
        input = MacUILib_getChar();
    }

    //set exit flag true if the inputted char is the esc key
    if (input == 27)
    {
        setExitTrue();
    }
}

//getter method for input
char GameMechs::getInput() 
{
    return input;
}

//getter method for score
int GameMechs::getScore() const
{
    return score;
}

//increments score by 1
void GameMechs::incrementScore()
{
    score++;
}

//getter for X length of board size
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

//getter for Y length of board size
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

//sets exit flag boolean true
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

//sets lose flag boolean as true
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

//sets input to a char passed through the function
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

//makes input null
void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

//this method generates a random food object on the game board that is not the snake's body
void GameMechs::generateFood(objPosArrayList* blockOff)
{
    //you only need to block off the player position for now... later will have to upgrade to iteration 3 (arrayList)
    //seed the random integer generation function with current time
    srand(time(NULL));
    bool done = false;

    //gets size of snake 
    int size = blockOff->getSize();
    int x, y = 0;

    while (done == false)
    {
        done = true;
        //randomly generated x and y coordinates for food
        x = rand()%(boardSizeX-2) +1;
        y = rand()%(boardSizeY-2) +1;
        //food symbol
        char sym = 'o';

        // check if coordinates overlap with player position
        for (int i = 0; i < size; i++){
            //sets done as false if any part of the snake's body is at the same location as the potential location of the generated food item
            if (x== blockOff->getElement(i).pos->x && y == blockOff->getElement(i).pos->y)
            {
                done = false;
            }
        }
    }
    //set food coordinates if it isnt the player position coordinates
    food.setObjPos(x, y, 'o');
}

//getter method for returning the food
objPos GameMechs::getFoodPos() const
{
    return food;
}
