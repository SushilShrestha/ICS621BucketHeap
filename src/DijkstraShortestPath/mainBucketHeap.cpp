#include <iostream>
#include <assert.h>
#include <list>
#include <chrono>
#include <fstream>

#include "../BucketHeap.h"
#include "../MinHeap.h"
#include "../BucketSignal.h"

using namespace std;
using namespace std::chrono;


struct AdjacentNode {
    int terminalVertex;
    int weight;
};

int main(){
    struct BucketItem currentVertex;
    int temp;

    int startVertex = 0, destination = 4;
    int numVertices, numEdges;
    int s, v, w;
    string line;

    BucketHeap* bucketHeap = new BucketHeap();

    cin >> numVertices >> numEdges;

    int* distance = new int[numVertices];
    list<struct AdjacentNode>* adjList = new list<struct AdjacentNode>[numVertices];

    for (int i = 0 ; i < numEdges ; i++){
        cin >> s >> v >> w;
        adjList[s].push_back({.terminalVertex=v, .weight=w});
    }

    auto start = high_resolution_clock::now();
    for (int i = 0 ; i < numVertices ; i++) {
        if (i == startVertex){
            bucketHeap->update(i, 0);
            distance[i] = 0;
        } else {
            bucketHeap->update(i, INT_MAX-1);
            distance[i] = INT_MAX-1;
        }
    }

    while (!bucketHeap->isEmpty()) {
        currentVertex = bucketHeap->deleteMin();

        if (currentVertex.key == destination) break;

        for (struct AdjacentNode n : adjList[currentVertex.key]) {
            if (distance[n.terminalVertex] > currentVertex.priority + n.weight) {
                distance[n.terminalVertex] = currentVertex.priority + n.weight;
                bucketHeap->update(n.terminalVertex, distance[n.terminalVertex]);
            }
        }
    }
    cout << distance[4] << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}
