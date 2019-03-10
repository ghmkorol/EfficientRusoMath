/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-1 Efficient Russian Multiplication
 * 
 * A La Russe Multiplication Algorithm class
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef ALARUSSE_H
#define ALARUSSE_H

// template <class ItemType>
class AlaRusse {
  private:
    int shiftCounter;
    unsigned long long DATA;
  public:    
    AlaRusse();
    void setData(unsigned long long data);
    unsigned long long getData() const ;
    int getNumberOfShifts() const ;
    void Multiply(int f);
}; // end AlaRusse
//  #include "AlaRusse.cpp"
#endif




