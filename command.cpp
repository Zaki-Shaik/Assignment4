#include "command.h"

void Command::initialize(Patron * ValidPatron, LibraryItem * ValidItem){
item = ValidItem;
patron = ValidPatron;

/*
 LibraryItem *item;  // Pointer to LibraryItem associated with command
    Patron *patron;     // Pointer to Patron associated with command 
    string commandName; // string of command name, eg: Checkout
*/

}
// void Command::initialize(Patron * ValidPatron, LibraryItem * ValidItem, Library& PassedLibrary){
// item = ValidItem;
// patron = ValidPatron;
// *LibraryPtr = PassedLibrary;

// /*
//  LibraryItem *item;  // Pointer to LibraryItem associated with command
//     Patron *patron;     // Pointer to Patron associated with command 
//     string commandName; // string of command name, eg: Checkout
// */

// }
    // Executes command logic. To be implemented by child classes

Command::Command(){




}
 
Command::~Command(){
     
 }