#include "objPosArrayList.h"


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{

    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];

    for (int i = 0; i < arrayCapacity; i++) {
        aList[i].pos->x = 0;
        aList[i].pos->y = 0;
        aList[i].symbol = '@';
    }

}

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


    if(listSize == arrayCapacity){
        return;
    }

    for(int i = listSize; i > 0; i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;

    listSize++;


}

void objPosArrayList::insertTail(objPos thisPos)
{

    aList[listSize++] = thisPos;

}

void objPosArrayList::removeHead()
{
    if(listSize ==0){
        return;
    }

    for(int i = 0; i < listSize-1; i++){
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize ==0){
        return;
    }
    listSize--;
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
