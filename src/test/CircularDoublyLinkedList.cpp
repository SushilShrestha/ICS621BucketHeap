#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;

CircularDoublyLinkedList::CircularDoublyLinkedList() {
    size = 0;
}

struct LinkListNode* CircularDoublyLinkedList::insertItem(int key, int priority) {
    struct LinkListNode* newNode = new struct LinkListNode;
    newNode->key = key;
    newNode->priority = priority;
    if (isEmpty()){
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;

        head = newNode;
    }
    size += 1;
    return newNode;
}

struct LinkListNode* CircularDoublyLinkedList::deleteItem(int key) {
    if (isEmpty()){
        return nullptr;
    }
    struct LinkListNode* tempPtr = head;
    for (int i = 0 ; i < size ; i++){
        if (tempPtr->key == key){
            tempPtr->next->prev = tempPtr->prev;
            tempPtr->prev->next = tempPtr->next;
            if (i == 0){
                // if it is head
                head = head->next;
            }
            size -= 1;
            return tempPtr;
        }
        tempPtr = tempPtr->next;

    }
    return nullptr;
}

void CircularDoublyLinkedList::display() {
    struct LinkListNode* tempPtr = head;
    for (int i = 0 ; i < size ; i ++){
        cout << tempPtr->key << " <-> ";
        tempPtr = tempPtr->next;
    }
    cout << tempPtr->key << endl;
}
