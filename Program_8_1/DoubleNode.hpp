//
//  DoubleNode.hpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/28/22.
//

#ifndef DoubleNode_hpp
#define DoubleNode_hpp

#include <stdio.h>

class Node {
public:
    int Value;
    Node * Next;
    Node * Previous;
};

class doubleNodeFunctions{
public:
    // implementation needed
    void printList(Node **n);
};
#endif /* DoubleNode_hpp */
