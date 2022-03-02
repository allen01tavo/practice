//
//  inStack.cpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/28/22.
//

#include "inStack.hpp"
#include <iostream>
using namespace std;

class inStack {
public:
    // Constructor
    inStack(int);
    // Copy constructor
    inStack(const inStack &);
    // Destructor
    ~inStack();
    
    //Stack Operations
    void push (int);
    void pop(int &);
    bool isFull() const;
    bool isEmpty() const;
    void print();
    
private:
    int *stackArray;    // Pointer to the stack array
    int stackSize;      // The stack size
    int top;            // Indicates the top of the stack
    
};

//Constructor
inStack::inStack(int size){
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

// Copy Constructor
inStack::inStack(const inStack &obj){
    // Create the stack array
    if (obj.stackSize > 0){
        stackArray = new int[obj.stackSize];
    }
    else{
        stackArray = NULL;
    }
    // Copy the stackSize attribute
    stackSize = obj.stackSize;
    
    // Copy the stack contents.
    for (int cnt = 0; cnt < stackSize; cnt++)
    {
        stackArray[cnt] = obj.stackArray[cnt];
    }
    // Set the top of the stack.
    top = obj.top;
}

// Destructor
inStack::~inStack(){
    delete [] stackArray;
}

// Member function isFull
bool inStack::isFull() const{
    bool status = false;
    if (top == stackSize - 1){
        status = true;
    }
    return status;
}

// Member function isEmpty
bool inStack::isEmpty () const{
    bool status = false;
    if (top == -1)
        status = true;
    return status;
}

// Member function push
void inStack::push(int num){
    if (inStack::isFull()){
        cout << "The stack is full." << endl;
    }
    else{
        top++;
        stackArray[top] = num;
    }
}

// Member function pop
void inStack::pop(int &num){
    if (isEmpty()){
        cout << " The stack is empty. " << endl;
    }
    else{
        num = stackArray[top];
        top--;
    }
}
// Member function print
void inStack::print(){
    if (isEmpty()){
        cout << " The stack is empty. " << endl;
    }
    else{
        // implementation needed
    }
}
