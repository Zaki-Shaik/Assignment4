//---------------------------------------------------------------------------
// bintree.CPP
// Binary Search Tree
// Authors: Zaki Shaik
//---------------------------------------------------------------------------
// bintree class:  Binary Tree class
//   includes  features:
//   -- allows output of the whole tree
//   -- allows insert and remove for the tree
//   -- gets sibling and parent of passed node
//   -- Turns a tree into a inorder array
//   -- turns array into a bstree
//
// Implementation and assumptions:
//   -- array is assumed to be sorted
//   -- Array has 100 elements
//   -- Only Passes string in the NodeData
//---------------------------------------------------------------------------
#include "bintree.h"
#include <iostream>



//----------------------------------------------------------------------------
// Default constructor 
// Preconditions: none
// Postconditions: sets root to null
BinTree::BinTree()
{
    root = nullptr;
}

//----------------------------------------------------------------------------
// copy constructor
// Preconditions: Need to pass a Bintree object to the function
// Postconditions: copies the tree
/*
BinTree::BinTree(const BinTree & tree)
{
    root = nullptr;
    *this = tree;
}
*/

//----------------------------------------------------------------------------
// Destructor()
// Preconditions: none
// Preconditions: Deallocates memory of the tree
BinTree::~BinTree() 
{
  
    makeEmpty();
    root = nullptr;
    
}
//----------------------------------------------------------------------------
// isEmpty()
// Preconditions: none
// Postconditions: checks to see if tree is empty and returns boolean
bool BinTree::isEmpty() const
{
    if(root == nullptr)
    {
        return true;
    }
    return false;
}

//----------------------------------------------------------------------------
// makeEmpty()
// Preconditions: none
// Postconditions: Empties the tree
void BinTree::makeEmpty()
{
    makeEmptyHelper(root);   
    
}

//----------------------------------------------------------------------------
// makeEmptyHelper()
// Preconditions: need to pass a Node object
// Postconditions: Empties the tree
void BinTree::makeEmptyHelper(Node*& current) const
{/*
    if(ptr != nullptr) // base case to end
    {
        makeEmptyHelper(ptr->left);
        makeEmptyHelper(ptr->right);


        if(ptr->data != nullptr) // deletes data
        {
            delete ptr->data;
            ptr->data = nullptr;
        }

        delete ptr;
        ptr = nullptr;
    }
    */
      if (current == nullptr) return;
   makeEmptyHelper(current -> left);
   makeEmptyHelper(current -> right);
   delete current -> data;
   current -> data = nullptr;
   delete current;
   current = nullptr;

}

//----------------------------------------------------------------------------
// operator=
// Preconditions: need to pass a BinTree object
// Postconditions: assigns the passed tree to this tree
BinTree & BinTree::operator=(const BinTree & tree)
{
    if(*this != tree) // if not equal call copy helper
    {
        makeEmpty();
        //copyHelper(root, tree.root);
    }
    return *this; // else returns current tree
}

//----------------------------------------------------------------------------
// copyHelper
// Preconditions: need to pass root and root of tree that needs to be 
// copied
// Postconditions: this tree has copied all the nodes from the cPtr
// void BinTree::copyHelper(Node*& ptr, const Node* cPtr) const
// {

//     if(cPtr != nullptr) 
//     {
//         ptr = new Node;
//         LibraryItem * tNode = new LibraryItem(*cPtr->data);
//         ptr->data = tNode;
//         ptr->left = cPtr->left;
//         ptr->right = cPtr->right;
//         copyHelper(ptr->left, cPtr->left);
//         copyHelper(ptr->right, cPtr->right);

//     }
// }

//----------------------------------------------------------------------------
// operator==
// Preconditions: need to pass a BinTree object
// Postconditions: returns a boolean if two trees are equal to each other
bool BinTree::operator==(const BinTree & rTree) const
{
    if((isEmpty() == true) && (rTree.isEmpty() == true)) // if both empty
    {
        return true;
    }
    else
    {
        return equalHelper(root, rTree.root);
       
    }
    
}

//----------------------------------------------------------------------------
// equalHelper
// Preconditions: need to pass root and root of tree that needs to be 
// compared
// Postconditions: returns a boolean if two trees are equal to each other
bool BinTree::equalHelper(const Node* ptr, Node* rPtr) const
{
    if(ptr == nullptr && rPtr == nullptr)
    {
        return true;
    }
    if(ptr != nullptr && rPtr != nullptr)
    {
        return (*ptr->data == *rPtr->data 
        && equalHelper(ptr->left, rPtr->left)     // checks left of tree
        && equalHelper(ptr->right, rPtr->right)); // only true if all true
    }
    return false;
}


//----------------------------------------------------------------------------
// operator!=
// Preconditions: need to pass a BinTree object
// Postconditions: returns a boolean if two trees are not equal 
// to each other
bool BinTree::operator!=(const BinTree & rTree) const
{
    return !(*this == rTree);
}



//----------------------------------------------------------------------------
// insert
// Preconditions: need to pass a NodeData Object
// Postconditions: returns a boolean if insertion of object was successful
bool BinTree::insert(LibraryItem*& value) 
{
    LibraryItem * temp;
    if(retrieve(*value, temp)) // checks for duplicates
    {
        return false;
    }
    Node* ptr = new Node; // exception is thrown if memory is not allocated
    
    ptr->data = value;
    
    ptr->left = ptr->right = nullptr;
    if (isEmpty()) {
      root = ptr;
    }
   else {
      Node* current = root;
      bool inserted = false;

      // if item is less than current item, insert in left subtree,
      // otherwise insert in right subtree
      while (!inserted) {
          if (*ptr->data == *current->data) return false;
         if (*ptr->data < *current->data) {
            if (current->left == nullptr) {      // at leaf, insert left
               current->left = ptr;
               inserted = true;
            }
            else
               current = current->left;          // one step left
         }
         else {
            if (current->right == nullptr) {     // at leaf, insert right
               current->right = ptr;
               inserted = true;
            }
            else
               current = current->right;         // one step right
         }
      }
   }
   return true;


}

//----------------------------------------------------------------------------
// retrieve
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if nodeData exists or not 
// and retrieves the node
bool BinTree::retrieve(const LibraryItem& data, LibraryItem*& rPtr) const
{

    retrieveHelper(root, data, rPtr);
    if(rPtr != nullptr)
    {
        return true;
    }
    return false;
}

//----------------------------------------------------------------------------
// retrieveHelper
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node and a Node ptr for root
// Postconditions: returns a boolean if nodeData exists or not 
// and retrieves the node
bool BinTree::retrieveHelper(Node * ptr, const LibraryItem& data, 
LibraryItem*& rPtr) const 
{
    if(ptr == nullptr)
    {
        rPtr = nullptr;
        return false;
    }
    // if the data matches return the pointer
    if(*ptr->data == data) 
    {
        rPtr = ptr->data;
        return true;
    }
    else if(*ptr->data > data) // if less step into the left
    {
        return retrieveHelper(ptr->left, data, rPtr);

    }


       return retrieveHelper(ptr->right, data, rPtr);
            
 


   
    
}

//----------------------------------------------------------------------------
// getSibling
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if sibling of the node exists and 
// returns the sibling
// bool BinTree::getSibling(const NodeData & data, NodeData& rData) const
// {
//     if(root == nullptr)
//     {
//         return false;
//     }
//    return getSiblingHelper(root, data, rData);
// }

//----------------------------------------------------------------------------
// getSiblingHelper
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node and a Node ptr for root
// Postconditions: returns a boolean if sibling of the node exists and 
// returns the sibling
// bool BinTree::getSiblingHelper(Node* ptr, const NodeData & data, 
// NodeData& rData) const
// {
//     if(ptr == nullptr || *ptr->data == data) 
//     {
        
//         return false;
//     }
//     // checks the left child
//     if(ptr->left != nullptr && *ptr->left->data == data) 
//     {
//         rData = *ptr->right->data;
//         return true;
//     }
//     // checks the right child
//     if(ptr->right != nullptr && *ptr->right->data == data)
//     {
//         rData = *ptr->left->data;
//         return true;
//     }
//     // check left subtree
//     bool sibling = getSiblingHelper(ptr->left, data, rData);
//     if(sibling) // if found within left subtree return sibling
//     {
//         return sibling;
//     }
//     // check right subtree
//     sibling = getSiblingHelper(ptr->right, data, rData);

//     return sibling;

// }

//----------------------------------------------------------------------------
// getParent
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if parent of the node exists and 
// returns the parent
// bool BinTree::getParent(const NodeData & data , NodeData& rData) const
// {
//     return getParentHelper(root, data, rData);
// }

//----------------------------------------------------------------------------
// getParentHelper
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if parent of the node exists and 
// returns the parent
// bool BinTree::getParentHelper(Node* ptr, const NodeData & data, 
// NodeData& rData) const
// {
//     if (ptr == nullptr || *ptr->data == data)
//     {
//         return false;
//     }
//     // check the left child
//     if(ptr->left != nullptr && *ptr->left->data == data)
//     {
//         rData = *ptr->data;
//         return true;
//     }
//     // check the right child
//     if(ptr->right != nullptr && *ptr->right->data == data)
//     {
//         rData = *ptr->data;
//         return true;
//     }
//     // check the left subtree
//     bool parent = getParentHelper(ptr->left, data, rData);
//     if(parent) // return the parent if found with the left subtree
//     {
//         return parent;
//     }
//     // check the right subtree
//     parent = getParentHelper(ptr->right, data, rData);

//     return parent;

// }
//----------------------------------------------------------------------------
// bstreeToArray
// Preconditions: need to pass a NodeData array
// Postconditions: fills a array with tree data using inorder traversal
// the tree is empty
// void BinTree::bstreeToArray(NodeData* array[])
// {
//     bstreeToArrayHelper(root, array, 0);

//     makeEmpty(); // empties the tree after passed to array
// }

//----------------------------------------------------------------------------
// bstreeToArrayHelper
// Preconditions: need to pass a NodeData array, Node ptr for root, 
// and index 
// Postconditions: fills a array with tree data using inorder traversal
// the tree is empty
// int BinTree::bstreeToArrayHelper(Node* ptr, NodeData* array[], int index)
// {
//     if(ptr == nullptr)
//     {
//         return index;
//     }

//     // iterating to the left
//     index = bstreeToArrayHelper(ptr->left, array, index);

//     NodeData * value;
//     value = ptr->data; // points the value to the data 
//     ptr->data = nullptr;
//     array[index] = value; // stores the value
//     index = index + 1; // increments the index
//     value = nullptr;

//     // iterates to the right
//     index = bstreeToArrayHelper(ptr->right, array, index);
//     return index;

// }

//----------------------------------------------------------------------------
// arrayToBSTree
// Parameter is an array of NodeData pointers
// Asssumes passed array of NodeData pointers is in inorder traversal
// and constructs BinTree from it
void BinTree::arrayToBSTree(LibraryItem * arrayOfNodeData[]) {
   int sizeOfArray = 0;

   // impossible to find size without helper method/passed parameter
   for (int i = 0; i < 100; i++) {
      if (arrayOfNodeData[i] != nullptr) {
         sizeOfArray++;
      }
   }
   if (sizeOfArray == 0) return;
   root = arrayToBSTree(arrayOfNodeData, 0, sizeOfArray - 1);
}

BinTree::Node * BinTree::arrayToBSTree(LibraryItem * arrayOfNodeData[],
int start, int end) {
   if (start > end) return nullptr;
   int middle = (start + end) / 2;

   // the max value is in the middle   

   Node* current = new Node; // exception is thrown if memory is not allocated
  // cout<<"current address"<<current;
    current->data = arrayOfNodeData[middle];
   // value = nullptr;
   //Node * current = new Node(arrayOfNodeData[middle]);
   arrayOfNodeData[middle] = nullptr;

   // left is lower half, so recursively construct lower half
   // and set left to lower half BST
   current -> left = arrayToBSTree(arrayOfNodeData, start, middle - 1);
   
   // right is upper half, so recursively construct upper half
   // and set right to upper half BST
   current -> right = arrayToBSTree(arrayOfNodeData, middle + 1, end);
   return current;
}


// //----------------------------------------------------------------------------
// // arrayToBSTree
// // Preconditions: need to pass a NodeData array
// // the tree is empty and array is sorted
// // Postconditions: fills a tree with array data
// void BinTree::arrayToBSTree(NodeData* array[])
// {
//     makeEmpty(); // empty tree

//     int high = 0; // number of elements in the array

//     for(int i = 0; i < 100; i++) // finds out how mant elements
//     {
//         if (array[i] != nullptr)
//         {
//             high++;
//         }
       
//     }
//     arrayToBSTreeHelper(array, 0, high-1);
// }

// //----------------------------------------------------------------------------
// // arrayToBSTreeHelper
// // Preconditions: need to pass a NodeData array,
// // 2 ints for splitting array
// // the tree is empty and array is sorted
// // Postconditions: fills a tree with array data
// // tree is balanced
// void BinTree::arrayToBSTreeHelper(NodeData* array[], int low, int high)
// {
//     if(low > high)
//     {
//         return;
//     }
//     else
//     {

//         int mid = (low + high) /2; // midpoint of the array 

//         NodeData * temp;
//         temp = array[mid]; // storing the array value at midpoint
//         insert(temp); // insert node
//         array[mid] = nullptr;

//         arrayToBSTreeHelper(array, low, mid-1); // left of array
//         arrayToBSTreeHelper(array, mid+1, high); // right of array
//     }

// }

//----------------------------------------------------------------------------
// displaySideways
// Preconditions: none
// Postconditions: displays the tree sidewqays
// void BinTree::displaySideways() const 
// {
//    sidewaysHelper(root, 0);
// }

//----------------------------------------------------------------------------
// sidewaysHelper
// Preconditions: need to passa Node for root of tree and int
// Postconditions: displays the tree sidewqays
// void BinTree::sidewaysHelper(Node* current, int level) const {
//    if (current != nullptr) {
//       level++;
//       sidewaysHelper(current->right, level);

//       // indent for readability, same number of spaces per depth level 
//       for(int i = level; i >= 0; i--) {
//           cout << "      ";
//       }

//       cout << *current->data << endl;        // display information of object
//       sidewaysHelper(current->left, level);
//    }
// }


//----------------------------------------------------------------------------
// operator<<
// Preconditions: need to pass ostream object and BinTree object
// Postconditions: prints the tree with inorder traversal
ostream & operator<<(ostream & output, const BinTree & tree)
{
    tree.inorderHelper(tree.root, output);
  
    return output;
}

//----------------------------------------------------------------------------
// inorderHelper
// Preconditions: need to pass a Node object for root of tree
// Postconditions: prints the tree with inorder traversal
// void BinTree::inorderHelper(const Node* ptr) const
// {
//     if(ptr != nullptr)
//     {
//         inorderHelper(ptr->left); // prints left sub tree
//         cout << *ptr->data << " ";
//         inorderHelper(ptr->right); // prints right subtree
//     }
// }
void BinTree::inorderHelper(const Node* ptr, ostream & out) const
{
    if(ptr != nullptr)
    {
        inorderHelper(ptr->left, out); // prints left sub tree
        //cout<<"data from ptr "<<*ptr->data<<endl;
        out << *ptr->data;
        inorderHelper(ptr->right, out); // prints right subtree
    }
}