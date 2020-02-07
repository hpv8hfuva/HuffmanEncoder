#include "heap.h"
#include "heapNode.h"
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

// include the standard I/O library
#include <stdio.h>

// we want to use parameters
void huffmancode(heapNode* a, map<char,string>* store, string code){
  if(a==NULL){
    return;
  }
  if(a->left == NULL && a->right == NULL){
      if(a->hold == ' '){
	cout << "space "<< code << endl;
	store->insert ( std::pair<char,string>(a->hold,code) );
      }
      else{
	cout << a->hold <<" "<< code << endl;
        store->insert ( std::pair<char,string>(a->hold,code) ); 
      }
    }
  huffmancode(a->left, store, code+"1");
  huffmancode(a->right,store, code+"0");
}

int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file.  FILE is a type designed to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
     FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    char g;
    int letter = 0;
    binary_heap* heapz =new binary_heap();
    map<char,int>* unique = new map<char, int>(); 
    while ((g = fgetc(fp)) != EOF ){
      if(g >= ' ' && g<='~'){ // if a valid char
	letter++;   
	std::map<char,int>:: iterator z;
	z = unique->find(g);
	if(z == unique->end()){ // if it does not find g, insert (g,1)
	  unique->insert(std::pair<char,int>(g,1));
	}
	else{//finds g 
	  int r = unique->at(g);
	  r++;
	  unique->erase(g);
	  unique->insert(std::pair<char,int>(g,r));//increase the frequency of g
	}
       }
    }
    int distinct = unique->size();
    for (std::map<char,int>::iterator pop=unique->begin(); pop!=unique->end(); ++pop){
      heapNode* combine = new heapNode(pop->second, pop->first);
      heapz->insert(combine);
    }
    while(heapz->size() >1){
      heapNode* first = heapz->deleteMin();
      heapNode* second = heapz->deleteMin();
      heapNode* firstNSecond = new heapNode();
      int freqFirst = first -> freq;
      int freqSecond = second -> freq;
      firstNSecond -> left = first;
      firstNSecond -> right = second;
      firstNSecond -> freq = (freqFirst + freqSecond);
      heapz->insert(firstNSecond);
    }
    map<char, string>* storage = new map<char, string>();
    huffmancode(heapz->findMin(),storage,"");
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    int zz = 0;
    rewind(fp);
    while ( (g = fgetc(fp)) != EOF ){
      if(g >= ' ' && g<='~'){
        string tempS = storage->at(g);
	zz = zz + tempS.length();
	cout << tempS << " ";
      }
    }
    fclose(fp);
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << letter << " symbols that are encoded." << endl;
    cout << "There are " << distinct <<" distinct symbols used." << endl;
    cout << "There were "<< letter*8 <<" bits in the original file." << endl;
    cout << "There were "<< zz <<" bits in the compressed file." <<endl;
    cout << "This gives a compression ratio of "<< letter*8.0/zz<<"." <<endl;
    cout << "The cost of the Huffman tree is "<< zz*1.0/letter<<" bits per character." <<endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the beginning
    /*rewind(fp);
    // read the file again, and print to the screen
    while ( (g = fgetc(fp)) != EOF )
        cout << g;
	// close the file*/
}
