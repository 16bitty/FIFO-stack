/*********************
 Name: Max Koeninger
 Programming Fundementals 3
 Purpose: a first in, first out stack using a linked list
 **********************/

#include "main.h"

int main(){
    srand(time(NULL));
    
    int ids[DATA_SIZE];
    string strs[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++){
        ids[i] = rand() % MAXID;
    }
    for (int i = 0; i < DATA_SIZE; i++){
        strs[i] = 32 + rand() % 95;
    }
    cout << "Displaying test data:" <<endl;
    for (int i = 0; i < DATA_SIZE; i++){
        cout << ids[i] << ": " << strs[i] <<endl;
    }
    LinkedList list1;
    for (int i = 0; i < DATA_SIZE; i++){
        cout << list1.addNode(ids[i], &strs[i]) <<endl;
    }
    return 0;
}
