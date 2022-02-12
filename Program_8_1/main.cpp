//
//  main.cpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/8/22.
//

#include <iostream>
#include "MyClass.cpp"
using namespace std;

// Function prototype
int searchList(int list[], int numElems, int value);
int searchList(int list[], int numElems, int value);
void arrayPrint();
void swap(int *xp, int *yp);
void bubblesort(int arr[], int size); // needs some work. It may not work

const int SIZE = 5;

int main(int argc, const char * argv[]) {
    int tests[SIZE] = {87, 75, 98, 100, 82};
    int results;
    MyClass classObject;        //creates an object of my class
    
    // search the array for 100.
    results = searchList(tests, SIZE, 0);
    
    // If searchlist retruned -1, then 100 was not found.
    if (results == -1)
        cout << "You did not earn 100 points on any test" << endl;
    else
    {
        // Otherwise results contains the subscript of
        // the first 100 found in the array.
        cout << "You earned 100 points on test ";
        cout << (results + 1) << endl;
    }
    classObject.Results(tests, SIZE, 82);
    arrayPrint();
    return 0;
}

// The searchlist function performs a linear search on an
// integer array.

int searchList(int list[], int numElems, int value){
    int index = 0;      // Used as subscript to search array
    int position = -1;  // To record position of search value
    bool found = false; // Flag to indicate if the value was found
    
    while (index < numElems && !found){
        if (list [index] == value)  {    // If the value is found
            found = true;                // Set the flag
            position = index;            // Record the value's subscript
        }
        index++;
    }
    return position;                    // Return the position, or -1
}

// The binarySearch fucntion performs a binary search on an
// integer array.

int binarySearch(int array[], int numelems, int value){
    
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
// function prints out an array
void arrayPrint(){
    string MONTHS[12] = {"January", "February", "March", "April",
                         "May", "June", "July", "August",
                         "September", "October", "November", "December" };
    const int NumberOfMotns = 12;
    int days[NumberOfMotns] = { 31, 28, 31, 30,
                                31, 30, 31, 31,
                                30, 31, 30, 31 };
    
    for (int count = 0; count < NumberOfMotns; count++){
        cout << MONTHS[count] << " has ";
        cout << days[count] << " days.\n";
    }
    
    const int size = 7;
    int numbers[size] = {2, 3, 4, 5}; // Initialize first 4 elements
    
    cout << "Here are the contents of the array: "<< endl;
    for (int index = 0; index < size; index++){
        cout << numbers[index] << endl;
    }
}
void swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}
void bubblesort(int arr[], int size){
    int i, j;
    for (i = 0; i < size- 1; i++){
        for(j = 0; j < size - i -1; j++){
            if (arr[j]  >  arr[j+1])
                swap(arr[j], arr[i+1]);
        }
    }
}
