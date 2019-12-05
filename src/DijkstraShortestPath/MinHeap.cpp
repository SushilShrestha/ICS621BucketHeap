#include "MinHeap.h"
#include<climits>
void swap(struct Vertex *x, struct Vertex *y);

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new struct Vertex[cap];
}

void MinHeap::insertKey(int vertex, int distance)
{
    if (heap_size == capacity)
    {
//        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;

    harr[i].distance = distance;
    harr[i].index = vertex;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].distance > harr[i].distance)
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

///// you cannot decrease key at index 0 !!!!!!!!!
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i].distance = new_val;
    while (i != 0 && harr[parent(i)].distance > harr[i].distance)
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

struct Vertex MinHeap::extractMin()
{
    if (heap_size <= 0) {
        struct Vertex temp;
        return temp;
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    struct Vertex root = harr[0];
    harr[0].distance = harr[heap_size-1].distance;
    harr[0].index = harr[heap_size-1].index;
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MAX);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].distance < harr[i].distance)
        smallest = l;
    if (r < heap_size && harr[r].distance < harr[smallest].distance)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::searchKey(int vertex) {
    for (int i = 0; i < heap_size ; i++ ){
        if (harr[i].index == vertex){
            return i;
        }
    }
    return -1;
}

void swap(struct Vertex *x, struct Vertex *y)
{
    int tempDistance = x->distance, tempIndex = x->index;
    x->distance = y->distance;
    x->index = y->index;

    y->distance = tempDistance;
    y->index = tempIndex;
}