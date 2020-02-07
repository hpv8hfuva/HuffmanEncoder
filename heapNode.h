//Hunter Vaccaro
//hpv8hf
//09/20/2019
//heapNode.h

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>

using namespace std;

class heapNode {
public:
    heapNode();                 // Constructor
    heapNode(int a, char b);
    int freq;
    char hold;
    heapNode *left, *right;	
};

#endif
