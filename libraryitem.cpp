
#include "libraryitem.h"
//#include <iostream>


LibraryItem::LibraryItem()
{
    initialize = false;
    ArrayOfParameters = nullptr;
    ArrayOfSortingPrio = nullptr;
    sizeOfArrayOfParameters = 0;
    sizeOfArrayOfSortingPrio = 0;
    CopiesLeft = -1;
    /*
           bool initialize;
        // initialize this for error checking later
        int MaxCopies;
        int CopiesLeft;
        string* ArrayOfParameters;
        int sizeOfArrayOfParameters;
        // for loop in createIt initializes this
        // this has a custom size, may be different from other arrays
        string** ArrayOfSortingPrio;
        int sizeOfArrayOfSortingPrio;
        string typeOfBook;
*/
    //ctor
}

// LibraryItem::LibraryItem(const LibraryItem& cLib)
// {
//     //copyLibrary(cLib);
// }

bool LibraryItem::operator==(const LibraryItem& rhs) const {
for (int i = 0; i < sizeOfArrayOfSortingPrio; i++){
//cout<<"1)"<<*ArrayOfSortingPrio[i]<<"SPACE"<<endl;
//cout<<"2)"<<*(rhs.ArrayOfSortingPrio[i])<<"SPACE"<<endl;
if (*ArrayOfSortingPrio[i] != *(rhs.ArrayOfSortingPrio[i]))
return false;
}
return true;

}

bool LibraryItem::operator!=(const LibraryItem& rhs) const {
    return ( !(*this == rhs) );
}



bool LibraryItem::operator<(const LibraryItem& rhs) const {
for (int i = 0; i < sizeOfArrayOfSortingPrio; i++){
if (*ArrayOfSortingPrio[i] < *(rhs.ArrayOfSortingPrio[i]))
return true;

if (*ArrayOfSortingPrio[i] > *(rhs.ArrayOfSortingPrio[i]))
return false;

}
return false;

}

bool LibraryItem::operator>(const LibraryItem& rhs) const {
return ( !(*this == rhs) ) && ( !(*this < rhs) );

}


int LibraryItem::getSizeOfArrayParametersArray()const{

return sizeOfArrayOfParameters;
    
}

LibraryItem::~LibraryItem()
{
    // research how subclasses inherit destructors
  
    
  
    
}

void LibraryItem::makeEmpty()
{
    
    for (int i=0; i < sizeOfArrayOfSortingPrio; i++){
ArrayOfSortingPrio[i] = nullptr;
        delete ArrayOfSortingPrio[i];
        
    }

    delete [] ArrayOfSortingPrio;
    delete [] ArrayOfParameters;


   

}
/*
LibraryItem* LibraryItem::createIt(){


}
*/
/*
void LibraryItem::OutputAll()
{
    if(!initialize)
    {
        return;
    }
    // cout<< "Library Items" << endl;
    // cout<< "AVAIL" << setw(2) << "Author"<< setw(15) << "TITLE"<< setw(15) << "YEAR"<< endl;
    for(int i = 0; i < sizeOfArrayOfParameters; i++)
    {
        cout.setf(ios::left, ios::adjustfield);
        cout << setw(10) << ArrayOfParameters[i];

    }
    
}
*/

string LibraryItem::atArrayIndex(int atIndex)
{
    return ArrayOfParameters[atIndex];
}

ostream & operator<<(ostream & out, const LibraryItem & item)
{
    int sizeOfItemParameters = item.sizeOfArrayOfParameters;
    out<< item.CopiesLeft<< "  ";
    out<<item.ArrayOfParameters[0];
    for (int i = 1; i < sizeOfItemParameters; i++){
       out<<' ';
       out<<item.ArrayOfParameters[i];

    }
    out<<endl;
    return out;
}

void LibraryItem::setCopiesLeft(int iterator)
{
    CopiesLeft = iterator;
}

int LibraryItem::getCopiesLeft()
{
    return CopiesLeft;
}

int LibraryItem::getMaxCopies(){

    return MaxCopies;
}