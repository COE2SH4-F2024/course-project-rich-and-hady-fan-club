#include "objPos.h"

//default constructor
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

//custom constructor that specifies the x and y coordinates, and symbol
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

// Destructor
objPos::~objPos(){
    delete[] this->pos; 
}

//Copy Constructor
objPos::objPos(const objPos &o)
{
    pos = new Pos;
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//Copy Assignmnet Operator
objPos& objPos::operator=(const objPos &o)
{
    if (this == &o)
    {
        return *this;
    }

    delete pos;

    pos = new Pos;
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
    
}

//setter to set a specified x and y coordinate, and symbol by taking in an objPos object
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//setter to set a specified x and y coordinate, and symbol
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//getter to get objPos values
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

//getter method that returns the symbol
char objPos::getSymbol() const
{
    return symbol;
}

//method that returns true or false if two objPos object's coordinates are equal
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

//getter that returns the symbool if two objPos object's coordinates are equal
//otherwise, returns 0
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
