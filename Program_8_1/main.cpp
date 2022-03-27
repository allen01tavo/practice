//
//  main.cpp
//  Program_8_1
//
//  Created by Gus Maturana on 2/8/22.
//

#include <iostream>
#include "MyClass.cpp"
#include "calculator.cpp"
using namespace std;

// Function prototype
int searchList(int list[], int numElems, int value);
void arrayPrint();
void swap(int *xp, int *yp);
void bubblesort(int arr[], int size); // needs some work. It may not work
void printList(Node* n, int size);
void insertAtTheFront(Node**head, int nValue);
void insertAtTheEnd(Node**head, int nValue);
void insertAfter(Node*previous, int nValue);

const int SIZE = 5;

int main(int argc, const char * argv[]) {
    int tests[SIZE] = {87, 75, 98, 100, 82};
    int results;
    MyClass classObject;        //creates an object of my class
    calculator objectCalculator; // creates an object of my calculator class
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    
    head->Value[0] = 1;
    head->Value[1] = 2;
    head->Value[2] = 4;
    head->Next = second;
    second->Value[0] = 0;
    second->Value[1] = 6;
    second->Value[2] = 5;
    second->Next = third;
    third->Value[0] = 0;
    third->Value[1] = 3;
    third->Value[2] = 5;
    third->Next = NULL;
    
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
    arrayPrint();
    cout << "122 is char value: "<< char(122) << endl;
    classObject.Results(tests, SIZE, 82);
    cout << "Value of pie: " << classObject.getPi() << endl;
    
    cout << "Ist it a letter?: " << classObject.IsLetter('D') << endl;
    
    // Calls out GuessGame
    classObject.GuessGame();
    cout << "Is 3 upper case?: " << classObject.IsUpperCase('3') << endl;
    cout << "Turn a to upper case " << classObject.ToUpperCase('a') << endl;
    string str = "Alabama, Alaska, Arizona, Arkansas, California, Colorado, Delaware, Florida, Georgia, Hawai, Idaho, "
                  "Illinois, Indiana, Iowa, kansas, Kentucky, Louisiana, Maine, Maryland, Massachusetts, Minnesota, Mississipi, "
                  "Montana, Missouri, Nebraska, Nevada, New Hampshire, New Jersy, New Mexico, New York, North Carolina, North Dakota, "
                  "Ohio, Okahoma, Oregon, Pensilvania, Rhode Island, South Carolina, South Dakota, Tennessee, Texas, Utah, Vermon, "
                  "Virginia, West Virginia, Washington, West Virginia, Wisconsin, Wyoming";
    
    cout << " The letter a appers " << classObject.LetterCount(str,'a') << " times in " << "\'" << str << "\'" << endl;
    
    objectCalculator.letterCount(str);
    cout << endl;
    
    string sentence = "The red fox was hunting a rabit when the hunter came and shoot the rabit."
                      "The red fox ran away and the rabbit ran as well. The hunter missed"
                      " We all found out that the fox was not a red fox, but a green fox.";
    string test = "  //// ....";
    string myWord = "and";
    
    cout<<"The word '" << myWord << "' appears " << objectCalculator.wordFind(sentence,myWord) << " times in sentence." << endl;
    
    string word = "O P Q C S D U M Z R";
    
    cout << "Normal Word: " << word << endl;
    cout << "Sort Word: " << objectCalculator.sortLetters(word) << endl;
    
    string rslt = objectCalculator.wordCompareResult("zapaTo", "zapa");
    cout << "wordcompareResult: "<< rslt << endl;
    
    cout << " Word Count " << objectCalculator.wordCount(str) << endl;
    
    cout << " Word Sort: " << endl;
    // To test the wordSort function
    string cities = "Barranquilla, Barrancabermeja, Atlanta, Barranca, Cartagena, Cartago, Zuluaga, Jakarta, Orlando, Tampa, Yucatan, Mexico, Opal, Mitu, Machupichu, Arauca, Villareal, Orcala, SanAndres, Mico, Caracas, Nasau, Martinique, Quiqui, Dulce, Zulu";
    // wordSort will sort the words alphabetically
    cout << objectCalculator.wordSort(cities) << endl;
    
    /**
    cout << " Printing linked list: " << endl;
    printList(head,3);
    insertAtTheFront(&head, -1);
    printList(head,3);
    insertAtTheEnd(&head, 10);
    printList(head,3);
    insertAfter(second, 100);
    printList(head,3);
        **/
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
        cout << numbers[index] << " ";
    }
    cout << endl;
}

// bubble sort algortihm
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
