//the objPos class defines the x and y coordinates, and a symbol for a given object

#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos();
        objPos(int xPos, int yPos, char sym);
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        //destructor
        ~objPos();

        //copy constructor
        objPos(const objPos &o);

        //copy assignment operator
        objPos& operator=(const objPos &o);

        //setters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

    //getters
        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif