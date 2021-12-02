#include "childrenbook.h"

/*
ChildrenBook::ChildrenBook()     // Class default constructor
{

}
*/

ChildrenBook::~ChildrenBook()    // Class destructor
{
    makeEmpty();
}

/*
bool ChildrenBook::setData(ifstream& file){
if (!initialize) return false;

for (int i=0; i<sizeOfArrayOfParameters; i++){
        string x;
        char checkEOL;
checkEOL = file.get();
if (checkEOL == '\n') return false;
getline(file, x, ',');
if (x.size() == 0) return false;
ArrayOfParameters[i] =x;

}
initialize = true;
return true;

}
*/
LibraryItem* ChildrenBook::createIt() const
{
    
    ChildrenBook *newChildrenBook= new ChildrenBook;

    newChildrenBook->ArrayOfParameters = new string[3];
    
    newChildrenBook->sizeOfArrayOfParameters = 3;
    newChildrenBook->CopiesLeft = 5;
    newChildrenBook->MaxCopies = 5;

    
    newChildrenBook->ArrayOfSortingPrio = new string*[2];
   
    newChildrenBook->sizeOfArrayOfSortingPrio = 2;

    newChildrenBook->ArrayOfSortingPrio[0] = &newChildrenBook->ArrayOfParameters[1];
    newChildrenBook->ArrayOfSortingPrio[1] = &newChildrenBook->ArrayOfParameters[0];
    
    return newChildrenBook;
}