/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-1 Efficient Russian Multiplication
 * 
 * Main driver program
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <memory>
#include <math.h>

#include "BSTnode.h"
#include "BST.h"
#include "AlaRusse.h"



using std::cout;
using std::endl;
using std::string;

// used to hold values of type int or values of unsigned long long int
// but not both - you may check the value - if the TVal.iVal < 0 then 
// access the value in TVal.ullVal for the correct value
using TVal = union
//union TVal
{
    int iVal = -1;                 // 16 bits; max_int 2147483647 2^31 - 1
    unsigned long long ullVal; // 64 bits; max_ullint 18446744073709551615 2^64-1
    
//     bool operator==(const TVal& other) const
//     {  
// 	return  ullVal == other.ullVal;
//     }
     
};





/**
 * Using a binary search tree and your alarusse object
 * compute the result of multiplying the numbers given
 * as command line arguments in the most efficient 
 * algorithmically
 * 
 * @param argc - the number of command line arguments
 *               includes the name of the program
 * @param argv - an array of character pointers representing
 *               each command line argument 
 */
int main(int argc, char* argv[])
{
    // initialize a binary search tree
    BST<TVal> multSearchTree;

    // initialize your alarusse object
    AlaRusse russe;
    russe.setData(25);
    russe.Multiply(16);
    russe.Multiply(7);
    russe.Multiply(4);
    russe.Multiply(3);
    russe.Multiply(2);
   
    
    cout << russe.getData() << " nShifts: "<< russe.getNumberOfShifts() <<  endl;
    
    // insert each of the command line arguments into
    // the binary search tree by converting each command
    // line argument to an integer and then inserting into the BST
    for (int ndx = 1; ndx < argc; ndx++) {
        // convert the command line argument to an int
        TVal nodeItem;
        
        nodeItem.iVal = atoi(argv[ndx]);
	
        // output the numbers processed
        cout << "Inserting " << nodeItem.iVal << " into BST." << endl;
        multSearchTree.insert(nodeItem);

        // insert argInt into binary search tree 
    } // end for
    // if BST is empty, return EXIT_FAILURE
    if(multSearchTree.isEmpty()) return EXIT_FAILURE;
    
    // perform alarusse with the tree in the most efficient way possible

    // output the result and the efficiency metric(s)
    cout << "Multiplication of the operands below is " << russe.getData() << endl;
    cout << "Shifts performed is " << russe.getNumberOfShifts() << " (via A La Russe)" << endl;
    cout << "Accesses for operands is " << " " << " (via AVL BST)" << endl;
    
    // terminate the application
    return EXIT_SUCCESS;
}
