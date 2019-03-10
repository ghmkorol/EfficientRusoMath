/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-1 Efficient Russian Multiplication
 * 
 * A La Russe Multiplication Algorithm implementation
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */



#ifndef ALARUSSE_IMP
#define ALARUSSE_IMP

#include "AlaRusse.h"


// template < class ItemType>
AlaRusse::AlaRusse()
{
  DATA = 1;
  shiftCounter=0;
} // end default constructor

// template < class ItemType>
void AlaRusse::setData(unsigned long long data)
{
  DATA = data;
  //shiftCounter=0;
} // end setData

// template < class ItemType>
unsigned long long AlaRusse::getData() const
{
  return DATA;
} // end getData

// template < class ItemType>
int AlaRusse::getNumberOfShifts() const 
{
  return shiftCounter;
}

// template <class ItemType>
void AlaRusse::Multiply(int f)
{
  unsigned long long sum = 0;
  unsigned long long m=DATA;
  for(int n=f;n>1;n=(n>>1),m=(m<<1)){
    shiftCounter+=2;
    if((n%2) != 0 ) sum+=m;
  }
  sum+=m;
  DATA=sum;
} // end 


#endif