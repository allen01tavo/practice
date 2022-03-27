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
// it will count the number of times a word appears in a sentence, paragraph or file.
int calculator::wordFind(string str, string word){
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
// Capitalizes all small letters
char calculator::toCapLtr(char ltr){
    int tmp = 0;
    if(int(ltr)>= 97 && int(ltr) <=122)
        tmp =  int(ltr) - 32;
    if( int(ltr)>= 65 && int(ltr) <= 90)
        tmp = int(ltr);
    
    return char(tmp);
}
// It converts capital letters into small letters
char calculator::toSmallLtr(char ltr){
    int tmp = 0;
    if(int(ltr) >= 97 && int(ltr) <= 122)
        tmp = int(ltr);
    if(int(ltr) >= 65 && int(ltr) <= 90)
        tmp = int(ltr) + 32;
    return char(tmp);
}
// It turns all capital letter in a word to small
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
// Returns the smallest value word when it compares two words
string calculator::wordCompare(string str1, string str2){
    string word;
    string w1 = "";
    string w2 = "";
    double size_ = 0;
    // compare two words and find out which one is greater
    if (str1 == str2){
        word = str1;
    }
    if (str1 != str2){
        if(str1.length() > str2.length()){
            size_ = str2.length();
        }
        else{
            size_ = str1.length();
        }
        // compares character by character
        for(int i = 0; i < size_; i++){
            // in case the characters are not equal
            if (int(str1[i]) != int(str2[i])){
                if(int(str1[i]) < int(str2[i])){
                    word = str1;
                    break;
                }
                else{
                    word = str2;
                    break;
                }
            }
            if (w1 == w2){
                if(str1.length() < str2.length()){
                    word = str1;
                    break;
                }
                else{
                    word = str2;
                    break;
                }
            }
            else {
                continue;
            }
            w1 += str1[i];
            w2 += str2[i];
        }
    }
    return word;
}
// to access wordCompare function since it is protected
string calculator::wordCompareResult(string s1, string s2){
    return calculator::wordCompare(s1,s2);
}
// Function return T or F depending if str1 is less than str2
bool calculator::wordsLessThan(string str1, string str2){
    bool rsl = false;
    string word;
    string w1 = "";
    string w2 = "";
    double size_ = 0;
    // compare two words and find out which one is lower
    if (str1 == str2){
        rsl = true;
    }
    if (str1 != str2){
        if(str1.length() > str2.length()){
            size_ = str2.length();
        }
        if (str1.length() < str2.length()){
            size_ = str1.length();
        }
        if (str1.length() == str2.length()){
            size_ = str1.length();
        }
        // compares character by character
        for(int i = 0; i < size_; i++){
            // in case the characters are not equal
            if (int(str1[i]) != int(str2[i])){
                if(int(str1[i]) < int(str2[i])){
                    rsl = true;
                    break;
                }
                else{
                    rsl = false;
                    break;
                }
            }
            if ((w1 == w2) && (i+1 == size_)){
                if(str1.length() < str2.length()){
                    rsl = true;
                    break;
                }
                else{
                    rsl = false;
                    break;
                }
            }
            if(w1 != w2){
                continue;
            }
            if(int(str1[i]) == int(str2[i])){
                continue;
            }
            w1 += str1[i];
            w2 += str2[i];
        }
    }
    return rsl;
}
// counts how many word are there in a string
int calculator::wordCount(string str){
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(int(' ') == int(str[i]) ){
            cnt++;
        }
    }
    return cnt + 1;
}
// use bubble sort to address sort the words alphabetically
// functions breaks the sentence into an array of strings and
// compares all words until it organize the words alphabetically
string calculator::wordSort(string list){
    int cnt = 0;
    int size = calculator::wordCount(list);
    string word[size];
    string tmp = "";
    
    // assigns the words to the array
    // length of list + 1 since we have to get the null char at the end of the string
    for (int i = 0; i < list.length()+1; i++){
        if(calculator::isLetter(list[i])){
            tmp += list[i];
        }
        else{
            if(tmp != ""){
                word[cnt] = tmp;
                tmp = "";
                cnt++;
            }
        }
    }
    // iterate through the whole aray and compare words
    for (int i = 0; i < size; i++) {
        // Last i elements are already in place
       for (int j = i+1; j < size; j++)
       {
           if (calculator::wordsLessThan(word[j], word[i])){
               tmp = word[i];
               word[i] = word[j];
               word[j] = tmp;
           }
       }
    }
    list = "";
    for (int i = 0; i < size; i++){
        list += word[i] + "\n";
    }
    return list;
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

