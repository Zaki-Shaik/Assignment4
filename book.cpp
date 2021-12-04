#include "book.h"

/*
Book::Book()  // Class default constructor
{

}
*/

/*
Book::~Book() // Class destructor
{
    
}
*/


// this assumes if the code is valid (type of media) the input format is correct
// sets the ifstream at the start of next line
// also assumes that the first character has been read and not the space after it
bool Book::setData(ifstream& file){

string x;
for (int i=0; i < sizeOfArrayOfParameters - 1; i++){
        
        char checkEOL;
checkEOL = file.get();
//cout<<"Char: "<<checkEOL<<" ";
//if (checkEOL == '\n') return false;
getline(file, x, ',');
//cout<< "x: " << x<<endl;
//if (x.size() == 0) return false;
ArrayOfParameters[i] =x;

}
file.get();
getline(file, x);
//if (x.size() == 0) return false;

ArrayOfParameters[sizeOfArrayOfParameters - 1] = x;

        

initialize = true;
return true;

}

bool Book::setData2(ifstream& file)
{
    string data; 
    for(int i = 0; i< sizeOfArrayOfSortingPrio; i++ )
    {   
        file.get();
        
        getline(file, data, ',');
        //cout<<"data is "<<data<<endl;
        *ArrayOfSortingPrio[i] = data;
       
    }

    getline(file, data); // this goes to the next line
    return true;
}


/*
LibraryItem* Book::createIt() const
{
        return new Book;
}
*/