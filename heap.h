// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include "heapNode.h"
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<heapNode*> vec);
    ~binary_heap();

    void insert(heapNode* x);
    heapNode* findMin();
    heapNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<heapNode*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
