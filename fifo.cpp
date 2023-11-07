/*********************
 Name: Max Koeninger
 Programming Fundementals 3
 Purpose: a first in, first out stack using a linked list
 **********************/

#include "fifo.h"
#include <iostream>

LinkedList::LinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList(){
    while(this->head && this->tail){
        this->deleteNode();
    }
    this->head = nullptr;
    this->tail = nullptr;
}

bool LinkedList::addNode(int idNum, string* info){
    bool added = false;
    if(idNum > 0 && *info != ""){
        Node *item = allocateNode(idNum, info);
        if(head == nullptr){
            head = item;
            tail = item;
        }
        else{
            item->prev = tail;
            item->prev->next = item;
            item->next = nullptr;
            tail = item;
        }
        added = true;
    }
    return added;
}

bool LinkedList::deleteNode(){
    bool deleted = false;
    Node *current = this->head;
    if(current){
        head = current->next;
        if(current->next){
            current->next->prev = nullptr;
            current->prev = nullptr;
        }
        delete current;
        current = nullptr;
        deleted = true;
    }
    return deleted;
}

bool LinkedList::peekNode(Data& item){
    bool peeked = false;
    if(this->head && this->head->data.id){
        item.id = this->head->data.id;
        item.information = this->head->data.information;
        peeked = true;
    }
    else{
        item.id = -1;
        item.information = "";
    }
    return peeked;
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
    stack = new LinkedList;
}

Stack::~Stack(){
    delete stack;
}

bool Stack::push(int id, string* info){
    return stack->addNode(id, info);
}

bool Stack::pull(Data& requestNode){
    bool pulled = stack->peekNode(requestNode);
    stack->deleteNode();
    return pulled;
}

bool Stack::peek(Data& requestNode){
    bool peeked = stack->peekNode(requestNode);
    return peeked;
}

bool Stack::isEmpty(){
    Data *bucket = new Data;
    bool empty = stack->peekNode(*bucket);
    return !empty;
}
