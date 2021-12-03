#include "patron.h"

Patron::Patron()
{
// LibraryItem** ItemHistory;
// int currentIndexOfItemHistory;
// int sizeOfItemHistory;
ItemHistory =new LibraryItem* [20];
sizeOfItemHistory = 20;
currentIndexOfItemHistory = 0;

CheckedOutBooks = new LibraryItem*[20];
currentIndexOfCheckedOutBooks = 0;
sizeOfCheckedOutBooks = 20;
    
}
void Patron::returnBook(const Command& command, LibraryItem* libraryitem){
// dereference library items to compare them with ==
for (int i =0; i < currentIndexOfCheckedOutBooks; i++){
if (*libraryitem == *CheckedOutBooks[i]){
// 1) swap it with the currentindex    
// book to be returned
LibraryItem* currentPtr = CheckedOutBooks[i];
// set current index book to end
CheckedOutBooks[i] = CheckedOutBooks[currentIndexOfCheckedOutBooks];
// set end to nullptr
CheckedOutBooks[currentIndexOfCheckedOutBooks] = nullptr;

// CheckedOutBooks[currentIndexOfCheckedOutBooks] = currentPtr;
// CheckedOutBooks[currentIndexOfCheckedOutBooks] -> 
// CheckedOutBooks[currentIndexOfCheckedOutBooks]

// 2) increment the amount of copies
currentPtr->setCopiesLeft(libraryitem->getCopiesLeft() + 1);
// 3) decrement the current index
currentIndexOfCheckedOutBooks--;
    return;
}

}

cout<<*libraryitem<<" not returned";

}

Patron::Patron(const Patron& pat)
{
    CommandHistory = pat.CommandHistory;

    id = pat.id;          // Patron's 4 numeric chars identifier
    firstName = pat.firstName;   // Patron's first name
    lastName = pat.lastName;
   // ItemHistory = pat.ItemHistory;

    sizeOfItemHistory = pat.sizeOfItemHistory;
    currentIndexOfItemHistory = pat.currentIndexOfItemHistory;   
   ItemHistory = new LibraryItem*[sizeOfItemHistory];
    
    for (int i = 0; i < pat.currentIndexOfItemHistory; i++)
    {

    ItemHistory[i] = pat.ItemHistory[i];
    
    }
sizeOfCheckedOutBooks = pat.sizeOfCheckedOutBooks;
currentIndexOfCheckedOutBooks = pat.currentIndexOfCheckedOutBooks;
CheckedOutBooks = new LibraryItem*[sizeOfCheckedOutBooks];
    for (int i = 0; i < pat.currentIndexOfCheckedOutBooks; i++)
    {

    CheckedOutBooks[i] = pat.CheckedOutBooks[i];
    
    }

    
}

// MAKE SURE WHEN CALLING THIS TO CHECK IF IT RETURNED TRUE
// otherwise THE number was out of range
bool Patron::constructPatron(ifstream& file){
       // string id;          // Patron's 4 numeric chars identifier
   // string firstName;   // Patron's first name
   //string lastName;    // Patron's last name

getline(file, id, ' ' );

if (id > "9999" || id <"0000"){
    getline(file, id);
   return false; 
}

getline(file, lastName, ' ' );

getline(file, firstName);

return true;
}

void Patron::addItemToCheckedOut
    (const Command& command, LibraryItem* libraryitem){
if (currentIndexOfCheckedOutBooks == sizeOfCheckedOutBooks){
LibraryItem** newArray = new LibraryItem* [sizeOfCheckedOutBooks + 10];
sizeOfCheckedOutBooks = sizeOfCheckedOutBooks + 10;
for (int i = 0; i < currentIndexOfCheckedOutBooks; i++){

    newArray[i] = CheckedOutBooks[i];
    CheckedOutBooks[i] = nullptr;
}
// no need to use a for loop to delete each element since
// all of them are transfered and nulled.
delete[] CheckedOutBooks;
CheckedOutBooks = newArray;

CheckedOutBooks[currentIndexOfCheckedOutBooks] = libraryitem;
currentIndexOfCheckedOutBooks++;
// insert it
// size++

}

else {
// insert it
// size++
CheckedOutBooks[currentIndexOfCheckedOutBooks] = libraryitem;
currentIndexOfCheckedOutBooks++;
}


    }


void Patron::setId(string newID)
{
    id = newID;
}

void Patron::addCommandToHistory
    (const Command& command,  LibraryItem* libraryitem) {

CommandHistory.push_back(command.getString());

if (currentIndexOfItemHistory == sizeOfItemHistory){
LibraryItem** newArray = new LibraryItem* [sizeOfItemHistory + 10];
sizeOfItemHistory = sizeOfItemHistory + 10;
for (int i = 0; i < currentIndexOfItemHistory; i++){

    newArray[i] = ItemHistory[i];
    ItemHistory[i] = nullptr;
}
// no need to use a for loop to delete each element since
// all of them are transfered and nulled.
delete[] ItemHistory;
ItemHistory = newArray;

ItemHistory[currentIndexOfItemHistory] = libraryitem;
currentIndexOfItemHistory++;
// insert it
// size++

}

else {
// insert it
// size++
ItemHistory[currentIndexOfItemHistory] = libraryitem;
currentIndexOfItemHistory++;
}



    }



Patron::~Patron()
{
 for (int i = 0; i< sizeOfItemHistory; i++){
    ItemHistory[i] = nullptr;

}
for (int i = 0; i< sizeOfCheckedOutBooks; i++){
    CheckedOutBooks[i] = nullptr;


    }

    delete[] ItemHistory;   
    delete[] CheckedOutBooks;
}



// int Patron::getSize() const
// {
//     return sizeOfItemHistory;
// }

void Patron::getHistory() const
{
   
    cout<< id << setw(10) << lastName << ", " << firstName << ":" << endl; 
   
    for(int i = 0; i < currentIndexOfItemHistory; i++)
    {
        if(ItemHistory[i] == nullptr)
        {
            continue;
        }
        else
        {
            cout<< CommandHistory.at(i) << ItemHistory[i];
        }
    }
   
}

bool Patron::operator<(const Patron& t) const{

    return (id < t.id);
}



Patron & Patron::operator=(const Patron& t)
{
    Patron copy(t);
    swap(copy);
    return *this;
}

void Patron::swap(Patron& copy)
{
    CommandHistory = copy.CommandHistory;
    sizeOfItemHistory = copy.sizeOfItemHistory;
    currentIndexOfItemHistory = copy.currentIndexOfItemHistory;
    id = copy.id;          // Patron's 4 numeric chars identifier
    firstName = copy.firstName;   // Patron's first name
    lastName = copy.lastName;

       ItemHistory = new LibraryItem*[sizeOfItemHistory];
    
    for (int i = 0; i < currentIndexOfItemHistory; i++)
    {

    ItemHistory[i] = copy.ItemHistory[i];
    
    }
    sizeOfCheckedOutBooks = copy.sizeOfCheckedOutBooks;
currentIndexOfCheckedOutBooks = copy.currentIndexOfCheckedOutBooks;
CheckedOutBooks = new LibraryItem*[sizeOfCheckedOutBooks];
    for (int i = 0; i < copy.currentIndexOfCheckedOutBooks; i++)
    {

    CheckedOutBooks[i] = copy.CheckedOutBooks[i];
    
    }
    
}

