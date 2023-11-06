/*********************
 Name: Max Koeninger
 Programming Fundementals 3
 Purpose: a first in, first out stack using a linked list
 **********************/

#ifndef FIFO_H
#define FIFO_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

class LinkedList {

public:
    LinkedList();
    ~Linkedlist();
    bool addNode(int, string*);
    bool deleteNode(int);
    
private:
    Node *head;
    Node *tail;
};

class Stack {
    
public:
    Stack();
    ~Stack();
    bool push(int, string&);
    bool pull(Data&);
    bool peek(Data&);
    bool isEmpty();
    
private:
    LinkedList **stack;
};
#endif
