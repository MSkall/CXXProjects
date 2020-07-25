QMAKE_CXXFLAGS += -Wno-c++11-extensions
CXXFLAGS ?= -std=c++11
CC = g++
CFLAGS = -c -Wall
CFLAGG = -Wall -g

all:

linkedlist: test_linkedlist.o
	$(CC) $(CFLAGG) -o linkedlist test_linkedlist.o
test_linkedlist.o: test_linkedlist.cpp linked_list_template.h
	$(CC) $(CFLAGG) -c test_linkedlist.cpp

heap: test_heap.o
	$(CC) test_heap.o -o heap
test_heap.o: test_heap.cpp heap_template.h
	$(CC) $(CXXFLAGS) $(CFLAGS) $(QMAKE_CXXFLAGS) test_heap.cpp

clean:
	rm -rf *o linkedlist heap