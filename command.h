// command.h
// Definition of class Command

#ifndef COMMAND_H
#define COMMAND_H

#include <string>  
#include "patron.h"
#include "libraryitem.h"

using namespace std;

//---------------------------------------------------------------------------
// Command: 
//
//  Implementation:
//
//  -- Defines an abstract Command class that models a library patron's command
//  -- (e.g. Checkout, Return, ShowHistory, Download, etc.)
//  -- All concrete forms of commands (e.g. Checkout, Return, ShowHistory, 
//     Download, etc.) will have to derive from it
//
//  Assumptions:
//
//  -- A Command is usually associated with a Patron's History of commands so 
//  -- storing a pointer to Patron looks redundant although it's preferable 
//  -- here since it gives us quick access to it's History (useful for 
//  -- ShowHistory command implementation)
//

class Patron;
class Command
{


public:
    Command();      // Class default constructor
    virtual ~Command();     // Class destructor

    //  Sets the Command's attributes
    void initialize( Patron * , LibraryItem *);

    // Executes command logic. To be implemented by child classes
    virtual bool execute() const = 0; 
    // returns string of command
  
    virtual string getString() const = 0;
    
    protected:
    LibraryItem *item;  // Pointer to LibraryItem associated with command
    Patron *patron;     // Pointer to Patron associated with command 
    string commandName; // string of command name, eg: Checkout


};

#endif
