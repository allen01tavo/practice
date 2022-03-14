//
//  calculator.hpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/12/22.
//

#ifndef calculator_hpp
#define calculator_hpp
#include <iostream>
#include <stdio.h>

class calculator{
    
public:
    // implementation needed
    void letterCount (string str);
    int singleLetterCount(string phrase, char ltr);
    bool isLetter(char letter); // identifies if the character is a letter
    int wordCount(string str, string word); // counts the number of words in a string
    string toSmallLetters(string word); // convert all letter to small
    string toCapLetters(string word); // covert all letters to capitals
    string sortLetters(string word);  // sort letter alpabetically
private:
    // implementation needed
protected:
    char toCapLtr(char ltr);
    char toSmallLtr(char ltr);
    void formatOutput(int n);
    void split(string str, char split);
};

// Linked list
class Node {
public:
    int Value[3] = {};
    Node * Next;
};
#endif /* calculator_hpp */
