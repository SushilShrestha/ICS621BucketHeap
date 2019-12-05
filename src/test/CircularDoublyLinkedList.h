#ifndef ICS621_CIRCULARDOUBLYLINKEDLIST_H
#define ICS621_CIRCULARDOUBLYLINKEDLIST_H


struct LinkListNode {
    LinkListNode *next;
    LinkListNode *prev;
    LinkListNode *root;
    LinkListNode *child;

    int key;
    int priority;

    int degree; // number of child nodes
    bool mark;  // node lost its child
};

class CircularDoublyLinkedList {
    int size;
    struct LinkListNode *head;
public:
    CircularDoublyLinkedList();
    struct LinkListNode* insertItem(int key, int priority);
    struct LinkListNode* deleteItem(int key);
    void display();

    bool isEmpty(){ return (size == 0);}
    int getSize() {return size;}
    struct LinkListNode* getHead(){
        return head;
    }

};


#endif //ICS621_CIRCULARDOUBLYLINKEDLIST_H
