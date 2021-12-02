#include "checkout.h"

Checkout::Checkout()
{

}


Checkout::~Checkout()
{

}

bool Checkout::execute() const
{
    //check for availibility of libraryitem
    int copiesLeft = item->getCopiesLeft();
    if(copiesLeft > 0)
    {
        item->setCopiesLeft(copiesLeft - 1);
        patron->addCommandToHistory(*this, item);
        return true;
    } 
    else
    {
        cout << "LibraryItem is not in Stock";
        return false;
    }
}

string Checkout::getString() const
{
    return "Checkout";
}