/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-1 Efficient Russian Multiplication
 * 
 * Balanced Search Tree class
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef BST_H
#define BST_H

#include <memory>

#include "BSTnode.h"

using std::shared_ptr;

// alias (typedef) for a templated void function pointer
template <class ItemType>
using func = void (*)(ItemType item);

// represents a binary search tree
template <class ItemType> 
class BST {
    private:
        // root of the binary search tree
        BSTnode_ptr<ItemType> root;

        // returns the height of the BST as an int
        int height(BSTnode_ptr<ItemType> node);

        // returns the largest height different of the BST as an int
        int diff(BSTnode_ptr<ItemType> node);

        // returns a shared pointer to the BST after performing a rr rotation
        // to reduce the height difference in the tree to 1
        BSTnode_ptr<ItemType> rrRotation(BSTnode_ptr<ItemType> node);

        // returns a shared pointer to the BST after performing a ll rotation 
        // to reduce the height different in the tree to 1
        BSTnode_ptr<ItemType> llRotation(BSTnode_ptr<ItemType> node);

        // returns a shared pointer to the BST after performing a lr rotation
        // to reduce the height difference in the tree to 1
        BSTnode_ptr<ItemType> lrRotation(BSTnode_ptr<ItemType> node);

        // returns a shared pointer to the BST after performing a rl rotation
        // to reduce the height difference in the tree to 1
        BSTnode_ptr<ItemType> rlRotation(BSTnode_ptr<ItemType> node);

        // returns a shared pointer to the BST after making the tree balanced
        // by computing the height difference and then performing required 
        // rotations to being the tree back into a height difference of 1
        BSTnode_ptr<ItemType> balance(BSTnode_ptr<ItemType> node);

    public:
        // constructor
        BST();

        // test whether the BST is empty or not
        bool isEmpty() const;

        // insert item into the BST
        void insert(const ItemType item);

        // remove the item from the BST
        void remove(const ItemType item);

        // find the item in the BST and return a pointer to the BSTnode
        // or return nullptr if not found in the BST
        BSTnode_ptr<ItemType> find(const ItemType item) const;

        // perform an inorder traversal of the BST 
        // calling f(item) at each visited node 
        void inorderTraversal(BSTnode_ptr<ItemType> node, func<ItemType>(item)) const;
}; // end BST class

#include "BST.cpp"
#endif