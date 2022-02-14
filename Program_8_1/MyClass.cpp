//
//  MyClass.cpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/11/22.
//

#include "MyClass.hpp"
#include <iostream>
using namespace std;
class MyClass{
    
    public:
    int myNum;     //  Attribute (int vriable;
    int binarySearch(int array[], int numelems, int value);
    void printSearch(int rslt);
    void Results(int array[], int numelems, int value);
    const double getPi(){
        return pi;
    }
    
    private:
    const double pi = 3.14; // constant value of pi
    
};

/** The binarySearch fucntion performs a binary search on an
    integer array. */
int MyClass::binarySearch(int array[], int numelems, int value){
    
    int first = 0,                  // First array element
        last = numelems - 1,        // Last array element
        middle,                     // Mid point of search
        position = -1;              // Position of search value
    bool found = false;             // Flag
    
    while (!found && first <= last){
        middle = (first + last)/2;  // Calculate mid pint
        if (array[middle] == value) // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)     // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;             // If value is in upper half
    }
    return position;
}
void MyClass::printSearch(int rslt){
    
    if (rslt == -1){
        cout << "We are inside myClass" << endl;
        cout << "You did not earn 100 points on any test" << endl;
    }
    else
    {
        // Otherwise results contains the subscript of
        // the first 100 found in the array.
        cout << "We are inside myClass" << endl;
        cout << "You earned 100 points on test ";
        cout << (rslt + 1) << endl;
    }
}
void MyClass::Results(int array[], int numElems, int value){
    
    int rslt = 0;
    rslt = binarySearch(array, numElems, value);
    printSearch(rslt);
    
}
