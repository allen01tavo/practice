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
    bool isLetter(char letter);
    int wordCount(string str, string word);
private:
    // implementation needed
protected:
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
