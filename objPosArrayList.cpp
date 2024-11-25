#include "objPosArrayList.h"


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    // Default to empty array  list
    listSize = 0;
    // Capacity is predefined in manual (memory on heap)
    arrayCapacity = ARRAY_MAX_CAP;

    // Create new array list
    aList = new objPos[arrayCapacity];

    // Iterate through and fill with default
    for (int i = 0; i < arrayCapacity; i++) {
        aList[i].pos->x = 0;
        aList[i].pos->y = 0;
        aList[i].symbol = '*';
    }

}

//taking out for now
/*
// Copy Constructor
objPosArrayList::objPosArrayList(const objPosArrayList &other)
{
    // Copy the size and capacity
    listSize = other.listSize;
    arrayCapacity = other.arrayCapacity;

    // Allocate memory for the array
    aList = new objPos[arrayCapacity];

    // Deep copy each objPos object in the array
    for (int i = 0; i < listSize; i++) {
        aList[i] = objPos(other.aList[i]);
    }
}


//Copy Assignmnet Operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other) {
    // Self-assignment check
    if (this == &other) {
        return *this;
    }

    // Clean up existing resources
    delete[] aList;

    // Copy listSize and arrayCapacity
    listSize = other.listSize;
    arrayCapacity = other.arrayCapacity;

    // Allocate new memory for aList
    aList = new objPos[arrayCapacity];

    // Deep copy the contents of other.aList
    for (int i = 0; i < listSize; i++) {
        aList[i].pos->x = other.aList[i].pos->x;
        aList[i].pos->y = other.aList[i].pos->y;
        aList[i].symbol = other.aList[i].symbol;
    }

    return *this;
}
*/

// Destructor
objPosArrayList::~objPosArrayList()
{
    // might need to delete all list members 
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Checks to see if the arrayCapacity has been hit
    if(listSize != arrayCapacity){
        // Move everything over 1 index to the right
        for(int i = listSize; i > 0; i--){
            aList[i] = aList[i-1];
        }
        // Add head element
        aList[0] = thisPos;
        // increase list size
        listSize++;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    // Insert at end of array list
    aList[listSize++] = thisPos;

}

void objPosArrayList::removeHead()
{   
    // Checks if there is a head
    if(listSize != 0){
        // Move everything one to the left
        for(int i = 0; i < listSize-1; i++){
            aList[i] = aList[i+1];
        }
        // Decrement list size
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    // Remove the last element
    if(listSize != 0){
        listSize--;
    }

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

    return aList[index];

}