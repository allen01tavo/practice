//
//  calculator.cpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/12/22.
//

#include "calculator.hpp"
#include <iostream>
using namespace std;


// Function counts and returns the number of letter that are use in a sentence
void calculator::letterCount (string str){
    int cnt = 0;
    // loop from a = 97 to z = 122
    for (int i = 97; i <= 122; i++){
        calculator::formatOutput(cnt);
        // char(i-32) capitazlize letter
        cout << char(i - 32) << ": " <<calculator::singleLetterCount(str, char(i))<< " ";
        cnt++;
    }
    cout << endl;
}
// Function is used to output letterCount
void calculator::formatOutput(int n){
    if (n % 5 == 0)
    {
        cout << endl;
    }
    else
    {
        cout << "\t\t";
    }
}
// count the number of letters in a sentence
int calculator::singleLetterCount(string str, char ltr){
    int cnt = 0;

    for (int i = 0; i < str.length(); i++){
        if (int(str[i]) == int(ltr) || int(str[i]) == int(toupper(ltr)) || (int(str[i])== (int(ltr) +32))){
            cnt++;
        }
    }
    return cnt;
}
// check if the character is a letter
bool calculator::isLetter(char letter){
    bool rslt = false;
    int x = int(letter);
    // from 65-90 Capital Letters, from 97-122 small letters
    if((x >= 65 && x <= 90)||(x >= 97 && x <= 122)){
        rslt = true;
    }
    return rslt;
}
// it will count the number of times a word appears in a sentence or paragraph.
int calculator::wordCount(string str, string word){
    int cnt = 0;
    string tmpWord = "";
    for (int i = 0; i < str.length(); i++){
        if(calculator::isLetter(str[i])){
            tmpWord+=str[i];
        }
        else{
            string tmp = calculator::toSmallLetters(tmpWord);
            tmpWord = "";
            if(tmp.compare(calculator::toSmallLetters(word)) == 0){
                cnt++;
            }
        }
    }
    return cnt;
}
// It capitalize small letters
char calculator::toCapLtr(char ltr){
    int tmp = 0;
    if(int(ltr)>= 97 && int(ltr) <=122)
        tmp =  int(ltr) - 32;
    if( int(ltr)>= 65 && int(ltr) <= 90)
        tmp = int(ltr);
    
    return char(tmp);
}
// It converts capital letter into small letters
char calculator::toSmallLtr(char ltr){
    int tmp = 0;
    if(int(ltr) >= 97 && int(ltr) <= 122)
        tmp = int(ltr);
    if(int(ltr) >= 65 && int(ltr) <= 90)
        tmp = int(ltr) + 32;
    return char(tmp);
}
// It turns all capital letter in a word small
string calculator::toSmallLetters(string word){
    string rsl = "";
    for(int i = 0; i < word.length(); i++){
        rsl+=calculator::toSmallLtr(word[i]);
    }
    return rsl;
}
// It capitalize all letters in a word
string calculator::toCapLetters(string word){
    string rsl = "";
    for(int i = 0; i < word.length(); i++){
        rsl+=calculator::toCapLtr(word[i]);
    }
    return rsl;
}
// short letters alpabetically (bubble sort algortihtm is used)
string calculator::sortLetters(string word){
    // implementation needed
    int i, j;
    char tmp;
    for (i = 0; i < word.length(); i++)
    {
        // Last i elements are already in place
       for (j = i+1; j < word.length(); j++)
       {
           if (int(word[j]) < int(word[i])){
               tmp = word[i];
               word[i] = word[j];
               word[j] = tmp;
           }
       }
    }
    return word;
}

// printlinked list class
class nodeFunctions {
public:
    // Print linked List
    void printList(Node* n, int size = 0){
        while(n!=NULL){
            if (size > 0){
                for (int i = 0; i < size; i++){
                    cout << n->Value[i] << endl;
                }
                n = n->Next;
            }
            else {
                cout << n->Value << endl;
                n = n->Next;
            }
        }
    }
    void insertAtTheFront(Node**head, int nValue){
        // 1. Prepare a newNode
        Node  * newNode = new Node();
        newNode->Value[0] = nValue;
        // 2. put it in front of current head
        newNode->Next = *head;
        // 3. Move head of the list to point to the new node
        *head = newNode;
        
    }
    void insertAtTheEnd(Node**head, int nValue){
        Node * newNode = new Node();
        newNode->Value[0] = nValue;
        newNode->Next = NULL;
        // 2. if linked list is empty, newNode will be a head node
        if (*head == NULL){
            *head = newNode;
            return;
        }
        // 3. Find the last node
        Node * last = *head;
        while (last->Next != NULL){
            last = last->Next;
        }
        // 4. Insert newNode after last node (at the end)
        last->Next = newNode;
    }
    void insertAfter(Node*previous, int nValue){
        //1. check if previous node is NULL
        if(previous == NULL){
            cout << "Previous cannot be NULL" <<endl;
            return;
        }
        //2. prepare a newNode
        Node * newNode = new Node();
        newNode->Value[0] = nValue;
        //3. Insrt newNode after prevous
        newNode->Next = previous->Next;
        previous->Next = newNode;
    }
    // returns an specific value stored in the Node array
    int rtnrValue(Node * n, int location = 0){
        return n->Value[location];
    }
};

