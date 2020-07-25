QMAKE_CXXFLAGS += -Wno-c++11-extensions
CXXFLAGS ?= -std=c++11
CC = g++
CFLAGS = -c -Wall
CFLAGG = -Wall -g

all:

linkedlist: linked_list_test.o
	$(CC) $(CFLAGG) -o linkedlist linked_list_test.o
linked_list_test.o: linked_list_test.cpp linked_list_template.h
	$(CC) $(CFLAGG) -c linked_list_test.cpp

heap: testheap.o
	$(CC) testheap.o -o heap
testheap.o: testheap.cpp heap_template.h
	$(CC) $(CXXFLAGS) $(CFLAGS) $(QMAKE_CXXFLAGS) testheap.cpp

clean:
	rm -rf *o linked list heap