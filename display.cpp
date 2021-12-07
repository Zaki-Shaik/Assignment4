#include "display.h"
#include "library.h"
Display::Display()
{

}

Display::~Display()
{

}
bool Display::execute() const
{
     if(LibraryPtr != nullptr)
     {
        cout<<*LibraryPtr;
         return true; 
     }
     return false;
}

string Display::getString() const
{
    return "Display";
}