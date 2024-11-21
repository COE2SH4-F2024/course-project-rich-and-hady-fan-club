#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; //Global pointer meant to instantiate a player object on the heap
GameMechs *myGM;

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

}

void GetInput(void)
{
    //collecting input ASCII character into GameMechanics object
    myGM->setInput(myGM->getInput());
}

void RunLogic(void)
{
    myGM->getInput();
    //if its the esc key
    if (myGM->getInput() == 27)
    {
        myGM->setExitTrue();
    }
    else 
    {
        myPlayer->updatePlayerDir();
        myPlayer->movePlayer();
    }
    //clear input
    myGM->clearInput();
}

void DrawScreen(void)
{

    MacUILib_clearScreen();  

    objPos playerPos = myPlayer->getPlayerPos();
    //call setFrame() to put the player symbol into the frame at the right coordinates
    myGM->setFrame(myPlayer->getPlayerPos().pos->x, myPlayer->getPlayerPos().pos->y, myPlayer->getPlayerPos().symbol);

    //print gameboard with frame and player
    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            MacUILib_printf("%c", myGM->getFrame(j, i));
        }
    }
    MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);  
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
