#include "return.h"

Return::Return()
{

}

Return::~Return()
{

}

bool Return::execute() const
{
    // will ask teacher if return requires max copies check

    int copiesLeft = item->getCopiesLeft();
if (copiesLeft == item->getMaxCopies() ) return false;

    item->setCopiesLeft(copiesLeft + 1);
    if(patron->returnBook(*this, item))
    {
        patron->addCommandToHistory(*this, item);
    }
    
   
    return true;
}

string Return::getString() const
{
    return "Return";
}
