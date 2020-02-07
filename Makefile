#Hunter Vaccaro
#hpv8hf
#Lab Section 11:00 am
CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -std=c++11
DEBUG = -Wall -g
.SUFFIXES: .o .cpp

huffmanencoder: heapNode.o heap.o huffmanenc.o
	$(CXX) $(DEBUG) heapNode.o heap.o huffmanenc.o

huffmanenc.o:huffmanenc.cpp 
	$(CXX) -c huffmanenc.cpp

heapNode.o:heapNode.cpp heapNode.h
	$(CXX) -c heapNode.cpp

heap.o: heap.cpp heap.h 
	$(CXX) -c heap.cpp 

clean:
	-rm *.o *~ huffmanencoder.exe
