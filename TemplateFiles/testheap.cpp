#include<iostream>
#include<vector>
#include "heap_template.h"

int main(){

    std::cout << "MaxHeap test: " << std::endl;
    MaxHeap<int> maxheap;

    maxheap.Insert(1);
    maxheap.Insert(2);
    maxheap.Insert(3);

    std::cout << "maxheap: ";
    maxheap.PrintHeap();

    maxheap.Insert(40);
    maxheap.Insert(14);
    maxheap.Insert(25);

    std::cout << "maxheap: ";
    maxheap.PrintHeap();
    
    std::cout << "top: " << maxheap.Top() << std::endl;

    maxheap.Pop();
    
    std::cout << "popping root" << std::endl;
    std::cout << "maxheap: "; 
    maxheap.PrintHeap();

    std::cout << "MinHeap test: " << std::endl;
    // MinHeap<int> minheap;

    // minheap.Insert(5);
    // minheap.Insert(10);
    // minheap.Insert(2);

    // std::cout << "minheap: ";
    // minheap.PrintHeap();

    // minheap.Insert(100);
    // minheap.Insert(-1);
    // minheap.Insert(-6);

    // std::cout << "minheap: ";
    // minheap.PrintHeap();
    // std::cout << "top: " << minheap.Top() << std::endl;

    // minheap.Pop();
    
    // std::cout << "popping root" << std::endl;
    // std::cout << "minheap: ";
    // minheap.PrintHeap();

    return 0;
}
