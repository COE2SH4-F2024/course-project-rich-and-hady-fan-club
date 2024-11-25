#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; //Global pointer meant to instantiate a player object on the heap
GameMechs *myGM;
objPosArrayList *myArrayList;

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
    myArrayList = new objPosArrayList();

    // Initialize first food object in the game
    myGM->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    //collecting input ASCII character into GameMechanics object
    myGM->collectAsyncInput();

}

void RunLogic(void)
{
    //for testing 2b
    // if (testing == 1)
    // {
    //      myGM->generateFood(myPlayer->getPlayerPos());
    // }
    // testing++;

    // if (testing == 20)
    // {
    //     myGM->generateFood(myPlayer->getPlayerPos());
    // }
    
    // Check if game is exiting
    if (myGM->getInput() == 27){
        myGM->setExitTrue();
    } 
    // Move player according to input
    else {
        myPlayer->updatePlayerDir();
        myPlayer->movePlayer();
    }
    // save head element position
    objPos head = myPlayer->getPlayerPos()->getHeadElement();
   
    //clear input
    myGM->clearInput();
}

void DrawScreen(void)
{

    MacUILib_clearScreen();  
    
    //storing coordinates in variables
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();

    objPos foodPos = myGM->getFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    //i = row, j = col
    //print gameboard with frame and player
    for (int i = 0; i < boardY; i++)
    {
       for (int j = 0; j < boardX; j++)
        {
            int check;
            //print player - iterate through each segment of the snake
            for (int k = 0; k < playerSize; k++){
                objPos thisSeg = playerPos->getElement(k);
                check = 0;
                // If i and j match the position of the segment, the body is printed and the check increments 
                if (i == thisSeg.pos->y && j == thisSeg.pos->x){
                    MacUILib_printf("%c", thisSeg.symbol);
                    check++;
                    break;
                }
                
            }
            //print food
            if (i == foodPos.pos->y && j == foodPos.pos->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            //blank space in gameboard (prints based on above nested for loops - where check increments)
            else if (i == 0 || i == boardY - 1 || j == 0 || j == boardX - 1)
            {
                //only put in a # around the boarder of the frame   
                MacUILib_printf("#");
                
            }
            else if (check == 0)
            //else if ((i > 0 && i < boardY - 1) && (j > 0 && j < boardX - 1))
            {
                MacUILib_printf(" ");
               
            }

        }
        MacUILib_printf("\n");
    }

    // Print score
    MacUILib_printf("Score: %d\n", myGM->getScore());
    
    // Check if game is over
    if (myGM->getLoseFlagStatus() == true){
        MacUILib_printf("YOU LOSE!");
        myGM->setExitTrue();
    }
    else if(myGM->getExitFlagStatus() == true){
        MacUILib_printf("GAME OVER!");
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
    delete myArrayList;

    MacUILib_uninit();
}
