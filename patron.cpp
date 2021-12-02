#include "patron.h"

Patron::Patron()
{
// LibraryItem** ItemHistory;
// int currentIndexOfItemHistory;
// int sizeOfItemHistory;
ItemHistory =new LibraryItem* [20];
sizeOfItemHistory = 20;
currentIndexOfItemHistory = 0;

    
}

Patron::Patron(const Patron& pat)
{
    CommandHistory = pat.CommandHistory;
    sizeOfItemHistory = pat.sizeOfItemHistory;
    currentIndexOfItemHistory = pat.currentIndexOfItemHistory;
    id = pat.id;          // Patron's 4 numeric chars identifier
    firstName = pat.firstName;   // Patron's first name
    lastName = pat.lastName;
   // ItemHistory = pat.ItemHistory;
   ItemHistory = new LibraryItem*[sizeOfItemHistory];
    
    for (int i = 0; i < pat.currentIndexOfItemHistory; i++)
    {

    ItemHistory[i] = pat.ItemHistory[i];
    
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

void Patron::addCommandToHistory
    (const Command& command,  LibraryItem* libraryitem) {

CommandHistory.push_back(command.getString());

if (currentIndexOfItemHistory = sizeOfItemHistory){
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
    delete[] ItemHistory;   
    
}

// this wil be called by library on each of the set elements
void Patron::deletePatron(){





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

// assumes string passed is 4 digit id
bool Patron::operator<(const string idNumber) const{

return (idNumber < id);
    
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
    
}