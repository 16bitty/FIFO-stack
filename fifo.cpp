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
    Node *current = this->tail;
    if(current){
        tail = current->prev;
        if(current->prev){
            std::cout<<current->prev->data.id <<std::endl;
            current->prev->next = nullptr;
            current->prev = nullptr;
        }
        delete current;
        current = nullptr;
        deleted = true;
    }
    return deleted;
}

bool LinkedList::pullNode(Data& item){
    bool pulled = false;
    if(this->head->data.id){
        item.id = this->tail->data.id;
        item.information = this->tail->data.information;
        pulled = true;
    }
    return pulled;
}

bool LinkedList::peekNode(Data& item){
    bool peeked = false;
    if(this->tail->data.id){
        item.id = this->tail->data.id;
        item.information = this->tail->data.information;
        peeked = true;
    }
    return pulled;
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
    bool pulled = stack->pullNode(requestNode);
    stack->deleteNode();
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
