#include <iostream>
#include <assert.h>
#include <list>
#include "../MinHeap.h"
#include "../BucketHeap.h"

using namespace std;


struct AdjacentNode {
    int terminalVertex;
    int weight;
};


int test();
int testBucketHeap();
list<struct AdjacentNode>* loadAdjacencyMatrix(int numVertices);

int main() {
    testBucketHeap();

}

int ain(){
    struct BucketItem currentVertex;
    int temp;

    int numVertices = 8;
    int startVertex = 0;
    MinHeap minHeap(numVertices);
    int distance[numVertices];

    list<struct AdjacentNode> adjList[numVertices];

    adjList[0].push_front({.terminalVertex=1, .weight=4});
    adjList[0].push_back({.terminalVertex=5, .weight=3});

    adjList[1].push_back({.terminalVertex=0, .weight=4});
    adjList[1].push_back({.terminalVertex=2, .weight=5});
    adjList[1].push_back({.terminalVertex=5, .weight=2});

    adjList[2].push_back({.terminalVertex=1, .weight=5});
    adjList[2].push_back({.terminalVertex=5, .weight=3});
    adjList[2].push_back({.terminalVertex=6, .weight=1});
    adjList[2].push_back({.terminalVertex=3, .weight=5});

    adjList[3].push_back({.terminalVertex=2, .weight=5});
    adjList[3].push_back({.terminalVertex=7, .weight=2});
    adjList[3].push_back({.terminalVertex=4, .weight=7});

    adjList[4].push_back({.terminalVertex=3, .weight=7});
    adjList[4].push_back({.terminalVertex=7, .weight=4});

    adjList[5].push_back({.terminalVertex=0, .weight=3});
    adjList[5].push_back({.terminalVertex=1, .weight=2});
    adjList[5].push_back({.terminalVertex=2, .weight=3});
    adjList[5].push_back({.terminalVertex=6, .weight=6});

    adjList[6].push_back({.terminalVertex=5, .weight=6});
    adjList[6].push_back({.terminalVertex=2, .weight=1});
    adjList[6].push_back({.terminalVertex=7, .weight=5});

    adjList[7].push_back({.terminalVertex=6, .weight=5});
    adjList[7].push_back({.terminalVertex=3, .weight=2});
    adjList[7].push_back({.terminalVertex=4, .weight=4});

    for (int i = 0 ; i < numVertices ; i++) {
        if (i == startVertex){
            minHeap.insertKey(i, 0);
            distance[i] = 0;
        } else {
            minHeap.insertKey(i, INT_MAX);
            distance[i] = INT_MAX;
        }
    }

    while (!minHeap.isEmpty()) {
        currentVertex = minHeap.extractMin();
        for (struct AdjacentNode n : adjList[currentVertex.key]) {
            if (distance[n.terminalVertex] > currentVertex.priority + n.weight) {
                distance[n.terminalVertex] = currentVertex.priority + n.weight;
                temp = minHeap.searchKey(n.terminalVertex);
                minHeap.decreaseKey(temp, distance[n.terminalVertex]);
            }
        }
    }
    cout << distance[4] << endl;

    test();
    return 0;
}


int test() {
    MinHeap minHeap(6);
    struct BucketItem temp;

    assert(minHeap.isEmpty() == true);
    minHeap.insertKey(1, 8);
    assert(minHeap.isEmpty() == false);
    temp = minHeap.getMin();
    assert(temp.priority == 8);
    minHeap.insertKey(1, 9);
    minHeap.insertKey(1, 1);
    minHeap.insertKey(1, 3);
    minHeap.insertKey(1, 10000);
    temp = minHeap.getMin(); assert(temp.priority == 1);
    temp = minHeap.extractMin(); assert(temp.priority == 1);
    temp = minHeap.extractMin(); assert(temp.priority == 3);

    minHeap.decreaseKey(2, 0);
    temp = minHeap.extractMin(); assert(temp.priority == 0);
    temp = minHeap.extractMin(); assert(temp.priority == 8);
    temp = minHeap.extractMin(); assert(temp.priority == 9);
    assert(minHeap.isEmpty() == true);

}


int testBucketHeap() {
    BucketHeap bucketHeap(2);
    assert(bucketHeap.getNumBucket() == 1);
    BucketHeap bucketHeap1(4);
    cout << bucketHeap1.getNumBucket();
    assert(bucketHeap1.getNumBucket() == 1);
}