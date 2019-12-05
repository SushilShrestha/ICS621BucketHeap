#include <iostream>
#include <assert.h>
#include "CircularDoublyLinkedList.h"
#include "FibonacciHeap.h"

using namespace std;


int main() {
    CircularDoublyLinkedList cdll;
    assert(cdll.isEmpty());
    cdll.insertItem(0, 90);
    assert(!cdll.isEmpty());
    assert(cdll.getSize() == 1);
    cdll.insertItem(1, 98);
    cdll.insertItem(2, 92);
    cdll.insertItem(3, 94);
    assert(!cdll.isEmpty());
    assert(cdll.getSize() == 4);
    cdll.deleteItem(2);
    assert(!cdll.isEmpty());
    assert(cdll.getSize() == 3);
    cdll.deleteItem(0);
    assert(!cdll.isEmpty());
    assert(cdll.getSize() == 2);
    cdll.insertItem(2, 920);
    cdll.insertItem(0, 900);
    assert(!cdll.isEmpty());
    assert(cdll.getSize() == 4);
    cdll.display(); // 0 <-> 2 <-> 3 <-> 1 <-> 0

    FibonacciHeap H;
    assert(H.getMin() == nullptr);
    return 0;
}