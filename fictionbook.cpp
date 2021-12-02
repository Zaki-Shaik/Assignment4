#include "fictionbook.h"

/*
FictionBook::FictionBook()      // Class default constructor 
{

}
*/

FictionBook::~FictionBook()    // Class destructor
{
    makeEmpty(); 
}

/*
bool FictionBook::setData(ifstream& file){
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
LibraryItem* FictionBook::createIt() const
{
    FictionBook *newFictionBook= new FictionBook;

    newFictionBook->ArrayOfParameters = new string[3];

    newFictionBook->sizeOfArrayOfParameters = 3;
    newFictionBook->CopiesLeft = 5;
newFictionBook->MaxCopies = 5;
    
    newFictionBook->ArrayOfSortingPrio = new string*[2];

    newFictionBook->sizeOfArrayOfSortingPrio = 2;

    newFictionBook->ArrayOfSortingPrio[0] = &newFictionBook->ArrayOfParameters[0];
    newFictionBook->ArrayOfSortingPrio[1] = &newFictionBook->ArrayOfParameters[1];
   
    
    
    return newFictionBook;
}
