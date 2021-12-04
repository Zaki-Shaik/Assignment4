// patron.h
// Definition of class Patron

#ifndef PATRON_H
#define PATRON_H

#include <string>
//#include "history.h"
#include <vector>

#include "command.h"

#include "libraryitem.h"
using namespace std;
//---------------------------------------------------------------------------
// Patron: 
//
//  Implementation:
//
//  -- Implements a library patron ADT as a Patron class
//
//  Assumptions:
//
//  -- Class is used for both storage and retrieval purposes/use cases
//  -- Patron's id is a numeric code of 4 characters
//

class Command;
class Patron
{


public:
    //Patron();   // Default class constructor
    // either takes a string 
    // assumes first char is read and then rest is passed
    Patron(); // construct 
    bool constructPatron(ifstream& file);
                                                          // constructor

    ~Patron();  // Class destructor
    Patron(const Patron&);
void returnBook(const Command& command, LibraryItem* libraryitem);
    // Adds a Command instance to History of patron
    void addCommandToHistory
    (const Command& command, LibraryItem* libraryitem);
    void addItemToCheckedOut
    (const Command& command, LibraryItem* libraryitem);
    // implement a method in command that returns a string 
Patron &operator=(const Patron& t);
bool operator<(const Patron& t) const;

//bool operator<(const string&) const;
//bool operator==(const string&) const;

    // Gets 
    //History getHistory();
    //int getSize() const;
    void getHistory() const;
    void swap(Patron&);
    void setId(string newID);
    string getId();

private:
    string id;          // Patron's 4 numeric chars identifier
    string firstName;   // Patron's first name
    string lastName;    // Patron's last name

vector<string> CommandHistory;
// remember that vectors can return size 
LibraryItem** ItemHistory;
LibraryItem** CheckedOutBooks;

int currentIndexOfItemHistory;
int sizeOfItemHistory;
int currentIndexOfCheckedOutBooks;
int sizeOfCheckedOutBooks;



    //History commandHistory; // Patron's history (list) of prior commands

};

#endif
