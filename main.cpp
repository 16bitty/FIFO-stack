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
    Data *bucket = new Data;
    for (int i = 0; i < DATA_SIZE; i++){
        std::cout << "aw212" << std::endl;
        std::cout << "aaa" << std::endl;
        cout << stack1.pull(*bucket) << ": ";
        std::cout << "a" << std::endl;
        cout << bucket->id << ": " << bucket->information <<endl;
        std::cout << "b" << std::endl;
    }
    
    
    return 0;
}
