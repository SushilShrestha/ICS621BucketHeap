#ifndef ICS621_MINHEAP_H
#define ICS621_MINHEAP_H

struct Vertex {
    int index;
    int distance;
};

class MinHeap {
    struct Vertex *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in heap
public:
    MinHeap(int capacity);

    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    struct Vertex extractMin();

    void decreaseKey(int i, int new_val);

    struct Vertex getMin() { return harr[0]; }

    bool isEmpty() { return heap_size == 0; }

    void deleteKey(int i);

    void insertKey(int vertex, int distance);

    int searchKey(int buildingRef);

    struct Vertex getItem(int index) {return harr[index];}

    int getSize(){return heap_size;}
};


#endif //ICS621_MINHEAP_H
