/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-1 Efficient Russian Multiplication
 * 
 * Balanced Search Tree Implementation
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef BST_IMP
#define BST_IMP

#include <memory>
#include<algorithm>

#include "BST.h"

template <class ItemType>
BST<ItemType>::BST() : root(nullptr)
{
} // end of constructor



//https://gist.github.com/SubCoder1/f32d1dd61112c6606a4841c197b0648c
template <class ItemType>
void BST<ItemType>::insert(ItemType item){
           if(root == nullptr){
	       BSTnode_ptr<ItemType> newnode;
               root = newnode;
               root->setItem(item);
	       root->setLeft(nullptr);
               root->setRight(nullptr);
           }
           else {
               auto linker = root;
               BSTnode_ptr<ItemType> newnode;
               newnode->setItem(item);
	       newnode->setLeft(nullptr);
               newnode->setRight(nullptr);
	       
               while(linker != nullptr){
                   if(linker->getItem().ullVal > item.ullVal){  ///!!!!!!
                       if(linker->getLeft() == nullptr){
                           linker->setLeft(newnode);
                           break; }
                       else { linker = linker->getLeft(); }
                   } else {
                       if(linker->getRight() == nullptr){
                           linker->setRight(newnode);
                           break; }
                       else {  linker = linker->getRight(); }
                   }
               }
               balance(newnode);
           }
}




// returns the height of the BST as an int
template <class ItemType>
int BST<ItemType>::height(BSTnode_ptr<ItemType> node)
{
    if(node==NULL) 
      return 0;
    else
      return 1 + std::max(height(node->getLeft()), height(node->getRight()));
}

// returns the largest height different of the BST as an int
template <class ItemType>
int BST<ItemType>::diff(BSTnode_ptr<ItemType> node){
  return height(node->getLeft())-height(node->getRight());
}

// returns a shared pointer to the BST after performing a rr rotation
// to reduce the height difference in the tree to 1
template <class ItemType>
BSTnode_ptr<ItemType> BST<ItemType>::rrRotation(BSTnode_ptr<ItemType> node){
    BSTnode_ptr<ItemType> temp;
    temp = node->getRight();
    node->setRight(temp->getLeft());
    temp->setLeft(node);
    return temp;
}

// returns a shared pointer to the BST after performing a ll rotation 
// to reduce the height different in the tree to 1
template <class ItemType>
BSTnode_ptr<ItemType> BST<ItemType>::llRotation(BSTnode_ptr<ItemType> node){
    BSTnode_ptr<ItemType> temp;
    temp = node->getLeft();
    node->setLeft(temp->getRight());
    temp->setRight(node);
    return temp;
}

// returns a shared pointer to the BST after performing a lr rotation
// to reduce the height difference in the tree to 1
template <class ItemType>
BSTnode_ptr<ItemType> BST<ItemType>::lrRotation(BSTnode_ptr<ItemType> node){
    BSTnode_ptr<ItemType> temp;
    temp = node->getLeft();
    node->setLeft(rrRotation(temp));
    return llRotation(node);
}

// returns a shared pointer to the BST after performing a rl rotation
// to reduce the height difference in the tree to 1
template <class ItemType>
BSTnode_ptr<ItemType> BST<ItemType>::rlRotation(BSTnode_ptr<ItemType> node){
    BSTnode_ptr<ItemType> temp;
    temp = node->getRight();
    node->setRight(llRotation(temp));
    return rrRotation(node);
}

// returns a shared pointer to the BST after making the tree balanced
// by computing the height difference and then performing required 
// rotations to being the tree back into a height difference of 1
template <class ItemType>
BSTnode_ptr<ItemType> BST<ItemType>::balance(BSTnode_ptr<ItemType> node)
{
    int bal_factor = diff(node);
    if (bal_factor > 1)
    {
        if (diff(node->getLeft()) > 0)
            node = llRotation(node);
        else
            node = lrRotation(node);
    }
    else if (bal_factor < -1)
    {
        if (diff(node->getRight()) > 0)
            node = rlRotation(node);
        else
            node = rrRotation(node);
    }
    return node;
}

template <class ItemType>
bool BST<ItemType>::isEmpty() const{
  if(root == nullptr)return true;
  else return false;
}




#endif