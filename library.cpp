#include "library.h"

Library::Library()
{
    sizeOfLibraryCollection = 16;
    libraryCollectionFactory = new BinTree* [16];
    

    for (int i = 0; i < 16; i++)
    {
        libraryCollectionFactory[i] = nullptr;

    }

    libraryCollectionFactory[2] = new BinTree;
   
   
    libraryCollectionFactory[5]= new BinTree;
   
    libraryCollectionFactory[15]= new BinTree;
   

// default factory ctor is designed for this

    mediaObject = new LibraryItemFactory;


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

 void Library::processCommands(ifstream& file){
/* pseudo code for command
// read first command and store it in a char
// check if its valid
// use set::find with the overloaded string comparison operator


    




*/
char command;
Command * temp;
    for(;;)
    {
        if(file.eof())
        {
            break;
        }

        file >> command;
        // add command valid checker here
        file.get();
        temp = commandObject->createCommand(hash(command));

        // create a library item and find it in the bintree
        // LibraryItem item;

        //          // and use that to get a pointer to the real library item

        // temp->initialize();
        // temp->execute();

        
    }


 }

ostream & operator<<(ostream & out, const Library &item)
{
     for (int i = 0; i < item.sizeOfLibraryCollection; i++ )
    {

        if (item.libraryCollectionFactory[i] != nullptr) out<<*item.libraryCollectionFactory[i];



    }
    return out;
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
            patronList.insert(temp);
            //temp = new Patron();
        }
        else
        {
            cout<<"Invalid Patron";
        }
       
       
   }

    for (std::set<Patron>::iterator it=patronList.begin(); it!=patronList.end(); ++it)
    {
           std::cout << ' ';
           it->getHistory();
    }
 
}