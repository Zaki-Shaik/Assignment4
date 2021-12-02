#include "showhistory.h"


ShowHistory::ShowHistory()      // Class default constructor
{

}
ShowHistory::~ShowHistory()     // Class destructor
{

}


bool ShowHistory::execute() const   // Overrides execute inherited from Command
{
    //patron->addCommandToHistory(*this, item);
    patron->getHistory();

    return true;
}

string ShowHistory::getString() const
{
    return "ShowHistory";
}