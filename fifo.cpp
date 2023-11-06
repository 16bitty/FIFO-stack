/*********************
 Name: Max Koeninger
 Programming Fundementals 3
 Purpose: a first in, first out stack using a linked list
 **********************/

#include "fifo.h"

LinkedList::LinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList(){
    Node *current = this->head;
    while(current){
        Node *temp = current->next;
        delete current;
        current = temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

bool LinkedList::addNode(int idNum, string* info){
    bool added = false;
    if(idNum > 0 && *info != ""){
        Node *item = allocateNode(idNum, info);
        tail = item;
        added = true;
    }
    return added;
}

bool LinkedList::deleteNode(){
    bool deleted = false;
    return deleted;
}

Node* LinkedList::allocateNode(int idNum, string* info){
    Node* item = new Node;
    item->data.id = idNum;
    item->data.information = *info;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
}

Stack::Stack(){
    
}

Stack::~Stack(){
    
}

bool Stack::push(int, string&){
    bool pushed = false;
    return pushed;
}

bool Stack::pull(Data&){
    bool pulled = false;
    return pulled;
}

bool Stack::peek(Data&){
    bool peeked = false;
    return peeked;
}

bool Stack::isEmpty(){
    bool empty = false;
    return empty;
}
