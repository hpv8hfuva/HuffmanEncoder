//Hunter Vaccaro
//hpv8hf
//9/8/2019
//heapNode.cpp

#include <iostream>
#include "heapNode.h"


using namespace std;

heapNode::heapNode(){ //default constructor
  freq = 0;
  hold = '\0';
  left = NULL;
  right = NULL;
}
heapNode::heapNode(int a, char b){ //parameterized constructor
  freq = a;
  hold = b;
  left = NULL;
  right = NULL;
}


