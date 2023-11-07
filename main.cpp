/*********************
 Name: Max Koeninger
 Programming Fundementals 3
 Purpose: a first in, first out stack using a linked list
 **********************/

#include "main.h"

int main(){
    srand(time(NULL));
    Data *bucket = new Data;
    bucket->id = -1;
    bucket->information = "";
    
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
    cout << "isEmpty:" << stack1.isEmpty() <<endl;
    cout << "Peeking:" <<endl;
    stack1.peek(*bucket);
    cout << bucket->id << ": " << bucket->information <<endl;
    for (int i = 0; i < DATA_SIZE; i++){
        cout << "Pushing:" <<endl;
        cout << stack1.push(ids[i], &strs[i]) <<endl;
        cout << "Peeking:" <<endl;
        stack1.peek(*bucket);
        cout << bucket->id << ": " << bucket->information <<endl;
    }
    cout << "isEmpty:" << stack1.isEmpty() <<endl;
    for (int i = 0; i < DATA_SIZE; i++){
        cout << "Pulling:" <<endl;
        cout << stack1.pull(*bucket) << ": ";
        cout << bucket->id << ": " << bucket->information <<endl;
        cout << "Peeking:" <<endl;
        cout << stack1.peek(*bucket) << ": ";
        cout << bucket->id << ": " << bucket->information <<endl;
    }
    cout << "isEmpty:" << stack1.isEmpty() <<endl;
    
    cout << "starting random testing..." <<endl;
    for (int i =0; i < RANDTESTSIZE; i++){
        int testNum = rand() % 1000;
        int testString = rand() % DATA_SIZE;
        switch(rand() % METHODS){
            case 0:
                cout << stack1.push(testNum, &strs[testString]) <<endl;
                break;
            case 1:
                cout << stack1.pull(*bucket) << ": ";
                cout << bucket->id << ": " << bucket->information <<endl;
                break;
            case 2:
                cout << stack1.peek(*bucket) << ": ";
                cout << bucket->id << ": " << bucket->information <<endl;
                break;
            case 3:
                cout << "isEmpty:" << stack1.isEmpty() <<endl;
                break;
        }
    }
    
    return 0;
}
