#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>  
#include <iostream>
#include <set>
#include "bintree.h"
#include "libraryitemfactory.h"
#include "libraryitem.h"
#include "patron.h"
#include "commandfactory.h"
using namespace std;

//---------------------------------------------------------------------------
// Library: 
//
//  Implementation:
//
//  -- Implements a Library (Manager) wrapper class that stores and manages 
//  -- various library items (Books, Periodicals, etc.) through an extensible 
//  -- set of commands (Checkout, Return, ShowHistory, Download, etc.)
//
//  Assumptions:
//
//  -- All library items, patrons and commands to be processed are initialized 
//  -- from external files
//

class Library
{
    friend ostream & operator<<(ostream &, const Library &);
private:
    string name;        // Library's name
  // Patron patrons;    // Collection of library Patrons
  // add dynamic size implementation later
    int sizeOfLibraryCollection;
    BinTree** libraryCollectionFactory; // Array of 
    // LibraryCollection instances (ChildrenBooks, FictionBooks, Periodicals) 
    // used used in a Factory pattern

    LibraryItemFactory * mediaObject;
    CommandFactory * commandObject;
    set<Patron> patronList;
    


    // Hash function that maps one mediaType character to a certain 
    // LibraryCollection instance in factory array
    int hash(char mediaType) const { return mediaType-'A'; } 
/*
    // Gets mediaType character out of line of text read from file
    char getMediaType(string line) const;

    // Gets command type out of line of text read from file
    char getCommandType(string line) const;

    // Gets patron Id our of line of text read from file
    int  getPatronIdFromCommand(string line) const;

    // Gets mediaType character out of line of text read from Commands file
    char getMediaTypeFromCommand(string line) const;
    */

public:
    Library();              // Class default constructor
    // add a custom implementation for library ctor
    // to make it 
    // it requires a custom 2nd constructor for factory too
    Library(string name);   // Class specialized constructor
    ~Library();             // Class destructor
    Library(const Library&);
    // Reads library Patrons from file and stores them in internal collection
    //void initializePatrons(string filePath);

    // Reads library items from file and stores them in internal collection
    void initializeLibraryItems(ifstream& file);

    // Reads commands from file and execute them sequentially 
    void processCommands(ifstream& file);

    void processPatrons(ifstream& file);
};

#endif
