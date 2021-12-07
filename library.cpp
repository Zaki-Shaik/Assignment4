#include "library.h"

Library::Library()
{
    sizeOfLibraryCollection = 16;
    libraryCollectionFactory = new BinTree* [16];
    // inserting hardCopy as types of media.
    TypeOfMedia.insert('H');

    for (int i = 0; i < 16; i++)
    {
        libraryCollectionFactory[i] = nullptr;

    }

    libraryCollectionFactory[2] = new BinTree;
   
   
    libraryCollectionFactory[5]= new BinTree;
   
    libraryCollectionFactory[15]= new BinTree;
   

// default factory ctor is designed for this

    mediaObject = new LibraryItemFactory;
commandObject = new CommandFactory;

/*
HashTable[2] = new ChildrenBook;
HashTable[5] = new FictionBook;
HashTable[15] = new Periodical;
*/


}

void Library::initializeLibraryItems(ifstream& file)
{
    
    LibraryItem * temp;
    char a;
    string x;

    for(;;)
    {
        if(file.eof())
        {
            break;
        }
        
        file.get(a);
                
        // check if char a is valid
        // add code for it here:
        
        // file type is stored in char a  
       
        // we need to make sure out of bounds later 
        // (for example, the size of the array is max hash('P')
        // anything larger than p would cause invalid read)
        if( (hash(a) < sizeOfLibraryCollection) && libraryCollectionFactory[hash(a)] != nullptr)
        {
            
            temp = mediaObject->createItem(hash(a));
            
            temp->setData(file);

            //NodeData* treeObj(temp);

            libraryCollectionFactory[hash(a)]->insert(temp);
            // store the object

        }
        else
        {
            cout << "Media Type does not exist" << endl;
            cout << "need to insert media type" << setw(3) << a << endl;
            getline(file, x);
        }    
        temp = nullptr;  
    }

    // intialize the libraryItem
    // Loop
    // get the char
    // call factory to create the object
    // Initialize the object
}
Library::~Library(){

    for (int i = 0; i < sizeOfLibraryCollection; i++)
    {
      delete libraryCollectionFactory[i];
      libraryCollectionFactory[i] = nullptr;

    // deleting nullptr is safe   
  
    }
    
    delete [] libraryCollectionFactory;
    libraryCollectionFactory = nullptr;
    // also have to delete the libraryfactoryitem
    delete  mediaObject;
    mediaObject = nullptr;
    delete commandObject;
    commandObject = nullptr;
 
    

    
}    // store object
    // end loop

 void Library::processCommands(ifstream & file) {
     /* pseudo code for command
     // read first command and store it in a char
     // check if its valid
     // use set::find with the overloaded string comparison operator
     */
     char command;
     Command * temp;
     Patron* currentPatron;
     LibraryItem* currentMediaObj;
  //   bool commmandNotFinished = true;
     // if u create a command object with valid parameters, then set this to false
     // check if this is true at the start of every if statement like this: commandNotFinished&&
     for (;;) {
         if (file.eof()) {
             break;
         }

         file >> command;
        //cout<<"here1"<<endl;
         if (commandObject -> checkValid(hash(command))) {
             // THIS INTO ELSE
             char checkEOL;

             checkEOL = file.get();
             //cout<<"COMMAND: "<<command<<endl;
             //cout<<"CHECK EOL"<<checkEOL<<"SPACE"<<endl;
             //cout << checkEOL << endl;

             if (file.eof() || checkEOL == '\n' ){           
             // old version commented out:
            // if (checkEOL == '\n' || file.eof()) {
                 temp = commandObject->createCommand(hash(command));
                 temp->initialize(currentPatron, currentMediaObj, this);
                 temp->execute();
                 
                continue;
                               // read 4 digit number string, if not valid call getline()
             }

             
             string IdNumber;
             file>>IdNumber;
             //cout<<"IdNumber: "<< IdNumber<<endl;
            // first check IDnumberchar length
            // then check each index of string to [3] using isdigit()
            
             if ( 
                 (IdNumber.size() == 4) &&
             isdigit(IdNumber[0]) &&
             isdigit(IdNumber[1]) &&
             isdigit(IdNumber[2]) &&
             isdigit(IdNumber[3])
              && patronList.find(IdNumber)->first == IdNumber           
              ) { // string is valid
            
            // we don't have eol check before we read this character since line 155
char EOLsecondCheck;
 EOLsecondCheck = file.get();
              if (EOLsecondCheck == '\n' || file.eof()) {
                 std::map<string, Patron>::iterator findIt;
findIt = patronList.find(IdNumber);

                 if (findIt != patronList.end()){ // valid
currentPatron = &findIt->second;
                 temp = commandObject->createCommand(hash(command));
                 temp->initialize(currentPatron, currentMediaObj);
                 temp->execute();
                 
                continue;

                 } else{

 continue;
                 }
                
                               // read 4 digit number string, if not valid call getline()
             }
             char typeOfBook;
             typeOfBook = file.get();
             // will use type of book if the next char is valid
             if( (hash(typeOfBook) < sizeOfLibraryCollection) &&
              libraryCollectionFactory[hash(typeOfBook)] != nullptr){
            file.get();
            char TypeOfCopy;
            TypeOfCopy = file.get();
            std::set<char>::iterator it;
            it = TypeOfMedia.find(TypeOfCopy);
            
            // have checked booktype is valid
            // make sure we can use this copyt to find the tree
            // need to delete the copy that factory makes after finding
            // its duplicate in bintree
            if (it != TypeOfMedia.end()) {
              
                // CALLED create item here
               LibraryItem* tempCopy = mediaObject->createItem(hash(typeOfBook));
               tempCopy->setData2(file); // check how this impacts set line
                 //cout << "tempcopy"<<*tempCopy << endl;
               LibraryItem* findCopy;
               
               libraryCollectionFactory[hash(typeOfBook)]->retrieve(*tempCopy, findCopy);
                //cout <<"findCopy" << findCopy << endl;
               if (findCopy != nullptr){ // copy is found and stored in findCopy, so delete tempCopy
                //cout << "exec" << endl; 
               delete tempCopy;
               
               // string IdNumber;
               std::map<string, Patron>::iterator findIt;
               findIt = patronList.find(IdNumber);
               if (findIt != patronList.end()){
                   currentPatron = &findIt->second;

                   // patron object and library item are all valid                   
                temp = commandObject -> createCommand(hash(command));
                temp->initialize(currentPatron, findCopy);
                temp->execute();               


               }
               else{
                   delete tempCopy;
            // string clear;
             //getline(file, clear); 

               }
               }
               else{
                    delete tempCopy;
            // string clear;
            // getline(file, clear);  

               }
                        


            }
            else{
            string clear;
             getline(file, clear);  
         

            }
             }
             else{
             string clear;
             getline(file, clear);  
             
               
             }

             }
              else{ //here
                 
             string clear;
             getline(file, clear);
             cout<<"There is no Patron with ID: " << IdNumber<<endl;
              }
                  
             } else {
                  string clear;
             getline(file, clear);
             

             }
             // create a library item and find it in the bintree
             // LibraryItem item;

             //          // and use that to get a pointer to the real library item

             // temp->initialize();
             // temp->execute();
             // THIS INTO ELSE

         } 

     }

 

ostream & operator<<(ostream & out, const Library &item)
{
     for (int i = 0; i < item.sizeOfLibraryCollection; i++ )
    {

        if (item.libraryCollectionFactory[i] != nullptr)
        {
            out<<*item.libraryCollectionFactory[i];
            //item.libraryCollectionFactory[i]->displaySideways();
        } 



    }
    
    return out;
}
void Library::outputAllItems(){

     for (int i = 0; i < sizeOfLibraryCollection; i++ )
    {

        if (libraryCollectionFactory[i] != nullptr)
        {
            cout<<libraryCollectionFactory[i];
            //item.libraryCollectionFactory[i]->displaySideways();
        } 



    }

}

void Library::processPatrons(ifstream& file)
{
   
   for(;;)
    {
        Patron temp;
        if(file.eof())
        {
            break;
        }  
        if(temp.constructPatron(file))
        {
            patronList.insert(pair<string,Patron>(temp.getId(), temp));
            //temp.getHistory();
          //  patronList.insert(temp);
            //temp = new Patron();
        }
        else
        {
            cout<<"Invalid Patron";
        }
       
       
   }

    // std::map<string,Patron>::iterator it = patronList.begin();
    // for(it=patronList.begin(); it!=patronList.end(); ++it)
    // {
    //     it->second.getHistory();

    // }
  /*  
    for (std::set<Patron>::iterator it=patronList.begin(); it!=patronList.end(); ++it)
    {
           std::cout << ' ';
           it->getHistory();
    }
 */
}