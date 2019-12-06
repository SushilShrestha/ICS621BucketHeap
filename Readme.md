# Implementation of Cache-Oblivious Priority Queue to Solve Single Source Shortest Path Problem 
## Final Project for ICS 621: Analysis of Algorithms
### Directories Structure
- **src** : contains all the source code and test cases
- **ProjectProposal** : contains latex file for project proposal
- **FinalReport** : contains latex file for final report proposal

*Overleaf link for final report is available [here](https://www.overleaf.com/9793274677skdvwfdzpcnm)*

## Compiling the RAM model algorithm with binary heap implementation
```
g++ -g -O2 -std=gnu++14 src/DijkstraShortestPath/main.cpp src/DijkstraShortestPath/MinHeap.cpp
```

## Compiling the Cache-Oblivious model algorithm with bucket heap implementation
```
g++ -g -O2 -std=gnu++14 src/DijkstraShortestPath/mainBucketHeap.cpp src/MinHeap.cpp src/BucketHeap.cpp src/BucketSignal.cpp
```

### Program input 
Sample input for the program is provided in `src/DijkstraShortestPath/smallgraph.txt` folder.

### Program output
The program will output the shortest path followed by total execution time of the program.




