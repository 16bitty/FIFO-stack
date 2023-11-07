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
        strs[i] = 32 + rand() % 94; //ensures printable character
    }
    cout << "Displaying test data:" <<endl;
    for (int i = 0; i < DATA_SIZE; i++){
        cout << ids[i] << ": " << strs[i] <<endl;
    }
    Stack stack1;
    cout << "Pushing:" <<endl;
    for (int i = 0; i < DATA_SIZE; i++){
        cout << stack1.push(ids[i], &strs[i]) <<endl;
    }
    cout << "Pulling:" <<endl;
    for (int i = 0; i < DATA_SIZE; i++){
        Data *bucket = new Data;
        cout << stack1.pull(*bucket) <<endl;
        cout << bucket->id << ": " << bucket->information <<endl;
    }
    
    
    return 0;
}
