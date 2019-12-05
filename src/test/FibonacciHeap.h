#ifndef ICS621_FIBONACCIHEAP_H
#define ICS621_FIBONACCIHEAP_H

#include "CircularDoublyLinkedList.h"


class FibonacciHeap {
    struct LinkListNode* min;
    CircularDoublyLinkedList rootList;
    int n;          // number of nodes in Fibonacci heap

public:
    void insert(int key, int priority){
        struct LinkListNode* newNode = rootList.insertItem(key, priority);
        if (min == nullptr){
            min = rootList.getHead();
        } else {
            if (newNode->key < min->key){
                min = newNode;
            }
        }
        n += 1;
    }

    struct LinkListNode* getMin(){return min;}

};


#endif //ICS621_FIBONACCIHEAP_H
