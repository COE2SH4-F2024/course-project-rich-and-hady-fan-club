#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;

    //frame, putting in spaces and #'s in a 2d matrix
    for (int i = 0; i < boardSizeY; i++)
    {
        for (int j = 0; j < boardSizeX; j++)
        {
            if ((i > 0 && i < boardSizeY - 1) && (j > 0 && j < boardSizeX - 1))
            {
                frame[i][j] = ' ';
                
            }
            else
            {
                //only put in a # around the boarder of the frame
                
                frame[i][j] = '#';
            }
        }
    }
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

    //frame, putting in spaces and #'s in a 2d matrix
    for (int i = 0; i < boardSizeY; i++)
    {
        for (int j = 0; j < boardSizeX; j++)
        {
            if ((i > 0 && i < boardSizeY - 1) && (j > 0 && j < boardSizeX - 1))
            {
                frame[i][j] = ' ';
                
            }
            else
            {
                //only put in a # around the boarder of the frame
                
                frame[i][j] = '#';
            }
        }
    }
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
    

char GameMechs::getInput() 
{
    if (MacUILib_hasChar() != 0){
        input = MacUILib_getChar();
    }
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score = score + 1;
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
//assigning  the 2d matrix frame value 
void GameMechs::setFrame(int x, int y, char symbol)
{
    frame[y][x] = symbol;
}

//getter for the 2d frame
char GameMechs::getFrame(int x, int y)
{
    return frame[y][x];
}