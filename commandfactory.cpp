#include "commandfactory.h"

CommandFactory::CommandFactory()
{
    factoryOfCommand = new Command*[18];
    sizeOfFactoryCommand = 18;

    for(int i = 0; i < sizeOfFactoryCommand; i++)
    {
        factoryOfCommand[i] = nullptr;
    }

    factoryOfCommand[7] = new ShowHistory;
    factoryOfCommand[17] = new Return;
    factoryOfCommand[2] = new Checkout;
    factoryOfCommand[3] = new Display;
}
// assumes checkValid is already called
    Command* CommandFactory::createCommand(int hashedChar) // Creates Command instances by 
{


    return factoryOfCommand[hashedChar];


}
bool CommandFactory::checkValid(int hashedChar) // checks if command char is valid
{
    if(hashedChar < sizeOfFactoryCommand && factoryOfCommand[hashedChar] != nullptr)
    {
        return true;
    }
    else
    {
        cout<< "invalid Command"<<endl;
        return false;
    }
    // return (hashedChar < sizeOfFactoryCommand && factoryOfCommand[hashedChar] != nullptr);
}

CommandFactory::~CommandFactory()
{
    for (int i = 0 ; i < sizeOfFactoryCommand; i++){

        delete factoryOfCommand[i];
        factoryOfCommand[i] = nullptr; 
    }

    delete [] factoryOfCommand;
    factoryOfCommand = nullptr;
}