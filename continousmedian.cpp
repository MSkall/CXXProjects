#include <iostream>
#include <iomanip>
#include <vector>
#include "heap_template.h"

double* continuousMedian(int arr[])
{
	// max heap for lower half, min heap for upper half

	// if heaps differ in size
	// take max of lower or min of higher (whichever is bigger)
	// if heaps same size -> avg lower max and higher min

	return 0;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	continuousMedian(arr);

	std::cout << "Test Max and Min Heaps" << std::endl;

	MaxHeap<int> maxheap;

	maxheap.Insert(1);
	maxheap.Insert(2);
	maxheap.Insert(3);

	maxheap.PrintHeap();

	maxheap.Insert(40);
	maxheap.Insert(14);
	maxheap.Insert(25);

	maxheap.PrintHeap();

	std::cout << "top: " << maxheap.Top() << std::endl;

	maxheap.Pop();

	maxheap.PrintHeap();

	return 0;
}