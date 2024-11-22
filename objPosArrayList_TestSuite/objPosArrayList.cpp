#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0; // DOUBLE CHECK NUMBER
    arrayCapacity = ARRAY_MAX_CAP;

    aList = new objPos[arrayCapacity];
    aList->pos->x = 0;
    aList->pos->x = 0;
    aList->symbol = '*';
}
    

objPosArrayList::~objPosArrayList()
{
    // Delete objPos but idk how yet
    delete[] aList;
}

// Copy Constructor


// Copy Assignment Operator



int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Exits if the arrayCapacity is hit
    if(listSize == arrayCapacity)
    {
        return;
    }

    listSize++;     // Increase the size of the List by one
    
    for(int i = listSize; i>0; i--)
    {
        aList[i] = aList[i-1]; // Shifting all elements towards the tail to create space at the head
    }
    // aList[0] is ready to be OVERWRITTEN by incoming value

    aList[0] = thisPos; // Inserting the element at the head, index: 0
    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        return;
    }

    for(int i=0; i<listSize-1; i++)
    {
        aList[i] = aList[i+1];  // Shifting towards the head, element i replaced by element i+1
    }
    listSize--; // Decrease the size of the list by one
}

void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        return;
    }

    listSize--; // Decrease the size of the list by one, Lazy Delete
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index>=0 || index <= listSize)
    {
        return aList[index];
    }
}