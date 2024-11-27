//this is the main project file of the snake game

#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

//time delay
#define DELAY_CONST 100000

//global pointers
Player *myPlayer; //Global pointer meant to instantiate a player object on the heap
GameMechs *myGM;
objPosArrayList *myArrayList;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//main() to run game
int main(void)
{
    Initialize();
    
    //loop is terminated when the exit flag is true
    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


//method that initializes variables
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //make new GameMechanic object
    myGM = new GameMechs();

    //puts GameMech's object into Player class
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
    //call methods to move snake
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    // save head element position
    objPos head = myPlayer->getPlayerPos()->getHeadElement();
   
    //clear input
    myGM->clearInput();
}

//method prints the a frame of the snake game in action
void DrawScreen(void)
{
    //clears the previous frame
    MacUILib_clearScreen();  
    
    //storing coordinates in variables
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();

    objPos foodPos = myGM->getFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

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
            
            else if (i == 0 || i == boardY - 1 || j == 0 || j == boardX - 1)
            {
                //only put in a # around the boarder of the frame   
                MacUILib_printf("#");
                
            }
            //blank space in gameboard (prints based on above nested for loops - where check increments)
            else if (check == 0)
            {
                MacUILib_printf(" ");
               
            }

        }
        MacUILib_printf("\n");
    }

    // Print score
    MacUILib_printf("Score: %d\n", myGM->getScore());
    
    // Check if game is over
    if (myGM->getLoseFlagStatus()){
        //if snake body hits itself
        MacUILib_printf("YOU LOSE!\n");
    }
    else if(myGM->getExitFlagStatus()){
        //if the user presss the esc key
        MacUILib_printf("GAME EXITS!\n");
    }
 
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //taking variables off the heap
    delete myPlayer;
    delete myGM;
    delete myArrayList;
    MacUILib_uninit();
}
