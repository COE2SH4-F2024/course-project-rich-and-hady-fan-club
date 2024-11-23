#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; //Global pointer meant to instantiate a player object on the heap
GameMechs *myGM;

// testing 2b
//static int testing = 1;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();
    
    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //make new GameMechanic object
    myGM = new GameMechs();
    myPlayer = new Player(myGM);

    //seed the random integer generation function with current time
    srand(time(NULL));

}

void GetInput(void)
{
    //collecting input ASCII character into GameMechanics object
    myGM->collectAsyncInput();

}

void RunLogic(void)
{
    //for testing 2b
    /*
    if (testing == 1)
    {
         myGM->generateFood(myPlayer->getPlayerPos());
    }
    testing++;

    if (testing == 20)
    {
        myGM->generateFood(myPlayer->getPlayerPos());
    }
    */
   
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    //clear input
    myGM->clearInput();
}

void DrawScreen(void)
{

    MacUILib_clearScreen();  
    
    //storing coordinates in variables
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = myGM->getFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    //i = row, j = col
    //print gameboard with frame and player
    for (int i = 0; i < boardY; i++)
    {
       for (int j = 0; j < boardX; j++)
        {
            //print player 
            if (i == playerPos.pos->y && j == playerPos.pos->x){
                MacUILib_printf("%c", playerPos.symbol);
            }
            //print food
            else if (i == foodPos.pos->y && j == foodPos.pos->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            //blank space in gameboard
            else if ((i > 0 && i < boardY - 1) && (j > 0 && j < boardX - 1))
            {
                MacUILib_printf(" ");
                
            }
            else
            {
                //only put in a # around the boarder of the frame   
                MacUILib_printf("#");
            }
        }
        MacUILib_printf("\n");
    }
 
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
