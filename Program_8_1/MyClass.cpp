//
//  MyClass.cpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/11/22.
//

#include "MyClass.hpp"
#include <iostream>
#include <cctype>
using namespace std;
class MyClass{
    
public:
    int myNum;     //  Attribute (int vriable);
    int binarySearch(int array[], int numelems, int value);
    void printSearch(int rslt);
    void GuessGame(int lower, int upper);
    void Results(int array[], int numelems, int value);
    bool IsLetter(char letter);
    int LetterCount(string phrase, char ltr);
    bool IsUpperCase(char ltr);
    char ToUpperCase(char ltr);
    //Constructor
    MyClass(int x = 0){
        number = x;};
    const double getPi(){
        return pi;
    }
    void setNumber(int x){
        number = x;
    }
    // Default of Number is 0
    int getNumber(){
        return number;
    }
    
private:
    const double pi = 3.14; // constant value of pi
    int number = 0;
    
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

void MyClass::GuessGame(int lower = 0, int upper = 100){
    setNumber(20);
    int guess;
    int guessCount = 0;
    do{
        cout << "Enter a number between " << lower <<" and " << upper <<": ";
        //request user input
        cin >> guess;
        guessCount++;
        // Checks for input range
        if (guess < 0 || guess > 100){
            cout << "Number is out side of the range 0 to 100" << endl;
        }
        // breaks while look if guessCount reaches 10
        if (guessCount == 10){
            break;
        }
        
    }while(guess != getNumber());
    
    if (guess == getNumber()){
        cout << "You Win! " << endl;
        cout << "Nubmer of tries: " << guessCount << endl;
    }
    else{
        cout << "You loose! " << endl;
        cout << "Number of tries: " << guessCount << endl;
        cout << "Correct Number was: " << getNumber() << endl;
    }
}

bool MyClass::IsLetter(char letter){
    bool rslt = false;
    int x = int(letter);
    // from 65-90 Capital Letters, from 97-122 small letters
    if((x >= 65 && x <= 90)||(x >= 97 && x <= 122)){
        rslt = true;
    }
    return rslt;
}
// count the number of letters in a sentence
int MyClass::LetterCount(string phrase, char ltr){
    int cnt = 0;

    for (int i = 0; i < phrase.length(); i++){
        if (int(phrase[i]) == int(ltr) || int(phrase[i]) == int(toupper(ltr)) || (int(phrase[i])== (int(ltr) +32))){
            cnt++;
        }
    }
    return cnt;
}
// returns true if the letter is upper case
bool MyClass::IsUpperCase(char ltr){
    bool Ucase = false;
    if(IsLetter(ltr)){
        if (int(ltr) >= 65 && int(ltr) <= 95){
            Ucase = true;
        }
    }
    else{
        cout << ltr << " is not a letter." << endl;
    }
    return Ucase;
}
// turns a lower letter into upper
char MyClass::ToUpperCase(char ltr){
    char rslt = ' ';
    
    if(IsLetter(ltr)){
        if (int(ltr) >= 65 && int(ltr) <= 95)
            rslt = ltr;
        else{
            rslt = char(int(ltr) - 32);
        }
    }
    else{
        cout << ltr << " is not a letter." << endl;
    }
    return rslt;
}
