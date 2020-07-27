#include <iostream>
#include <vector>

/* (focusing on binary heaps) - node has up to 2 children
 * Heap functionality: heap is a data structure that has the form of a tree

 * MIN HEAP
 * main property: every node must be lower than each of its children (large at bottom, small at top)
 * lowest element is at its root -- min_heap
 * MAX HEAP
 * main property: children are lower than their parents
 * largest element is at the root

 * implementation:
 * method 1: dynamic allocation for each node, with 2 pointers pointing to children
 * method 2 (better): represent as array
 	- perform "level order traversal" of heap
 	- array starts with element at root, then follows with children of that root, then all children of those children
 	- greatest element is at the first posiition of the array
 	- array representation: https://www.geeksforgeeks.org/building-heap-from-array/

 * notes:
 * left child: 2(i+1) - 1
 * right child: 2(i+1)
	OR
 * Root is at index 0 in array.
 * Left child of i-th node is at (2*i + 1)th index.
 * Right child of i-th node is at (2*i + 2)th index.
 * Parent of i-th node is at (i-1)/2 index.
 * last non-leaf node: (n/2) - 1

 * arrange numbers from vector to heap with std::make_heap
 	std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::make_heap(numbers.begin(), numbers.end());
	for (int number : numbers)
	{
	    std::cout << number << ' ';
	}
*/

// Greater and Smaller are used as comparators 
template <class T>
bool GreaterComp(T a, T b) 
{ 
    return a > b;
} 

template <class T>
bool SmallerComp(T a, T b) 
{ 
    return a < b;
} 

enum HeapType {MAXHEAP, MINHEAP};

// template
// https://gist.github.com/truncs/1810804
// https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
template <class T>
class Heap {
public:
	Heap(bool (*c)(T, T), HeapType type) : comp(c), heapType(type) {
		heapSize = -1;
	}
	void Swap(int child, int parent);
	void PrintHeap();
	virtual ~Heap() { }

	// want pure virtual because we're creating min and max heaps
	virtual void Insert(int i) = 0;
	virtual void Pop() = 0;
    virtual int Top() = 0;
    virtual int GetSize() = 0; 

protected: // accessible in the class that defines them and in classes that inherit from that class
	std::vector<T> A;
	int heapSize;
	bool (*comp)(T, T);
	HeapType heapType;
	
	int GetLeftChild(int i)
	{
		return (2 * i + 1);
	}

	int GetRightChild(int i)
	{
		return (2 * i + 2);
	}

	int GetParent(int i)
	{
		return (i - 1) / 2; 
	}

	int size()
	{
		return A.size();
	}

	void insert(int i)
	{
		Heap<T>::A.push_back(i);

		// need to call heapify_up to satisfy heap property
		// to do that, need index
		// index will be the size of vector - 1 as we've just added a new element
		int index = GetSize() - 1;

		if(heapType == MAXHEAP)
		{
			max_heapify_up(index);
		}
		else
		{
			min_heapify_up(index);
		}
	}

	int top()
	{
		try {
			// if heap has no elements, throw an exception
			if (GetSize() == 0)
				throw std::out_of_range("Vector<X>::at() : "
						"index is out of range(Heap underflow)");

			return A[0];
		}
		// catch and print the exception
		catch (const std::out_of_range& oor) {
			std::cout << "\n" << oor.what();
		}

		return -1;
	}

	void pop()
	{
		// replace root of heap with last element of vector
		A[0] = A.back(); // return last element of vector
		A.pop_back(); // remove last element of vector

		// heapify down since we just move child to root
		if(heapType == MAXHEAP)
		{
			max_heapify_down(0);
		}
		else
		{
			min_heapify_down(0);
		}
	}

	void max_heapify_down(int i)
	{
		int left = GetLeftChild(i);
		int right = GetRightChild(i);

		// node that is violating heap
		// setting it to the largest because we go in assuming heap is correct
		// i.e. node i is larger than children
		int curr_largest = i;

		// compare node i with it's child, if its lower, needs to swap
		// set largest to now be either left or right child
		if(left < size() && A[left] > A[i])
		{
			curr_largest = left;
		}
		if(right < size() && A[right] > A[curr_largest])
		{
			curr_largest = right;
		}

		// swap with child that has greater value (left or right)
		// then call heapify_down on child
		if(curr_largest != i) { // as in we found that it was violating
			Swap(curr_largest, i);
			max_heapify_down(curr_largest);
		}
	}

	void max_heapify_up(int i)
	{
		int parent = GetParent(i);

		if(A[i] > A[parent])
		{
			Swap(i, parent);
			max_heapify_up(parent);
		}
	}

	void min_heapify_down(int i)
	{
		int left = GetLeftChild(i);
		int right = GetRightChild(i);

		int curr_smallest = i;

		if(left < size() && A[left] < A[i])
		{
			curr_smallest = left;
		}
		if(right < size() && A[right] < A[curr_smallest])
		{
			curr_smallest = right;
		}

		if(curr_smallest != i) {
			Swap(curr_smallest, i);
			min_heapify_down(curr_smallest);
		}
	}

	// move the node up in the heap if we find it is smaller than the parent
	void min_heapify_up(int i)
	{
		int parent = GetParent(i);

		if(A[i] < A[parent])
		{
			Swap(i, parent);
			min_heapify_up(parent);
		}
	}
};

template <class T>
void Heap<T>::Swap(int child, int parent) {
	T temp;
	temp = A[child];
	A[child] = A[parent];
	A[parent] = temp;
}

template <class T>
void Heap<T>::PrintHeap()
{
	for(int i = 0; i < GetSize(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

// MIN-MAX HEAP Implementation
// https://www.techiedelight.com/min-heap-max-heap-implementation-c/
template <class T>
class MaxHeap : public Heap<T> {
public:
	MaxHeap() : Heap<T>(&GreaterComp, MAXHEAP) {}
	~MaxHeap() { }

	int GetSize() { return Heap<T>::size(); }
	void Insert(int i) { Heap<T>::insert(i); }
	void Pop() { Heap<T>::pop(); }
	int Top() { return Heap<T>::top(); }
};

template <class T>
class MinHeap : public Heap<T> {
public:
	MinHeap() : Heap<T>(&SmallerComp, MINHEAP) {} 
	~MinHeap() {}

	int GetSize() { return Heap<T>::size(); }
	void Insert(int i) { return Heap<T>::insert(i); }
	void Pop() { Heap<T>::pop(); }
	int Top() { return Heap<T>::top(); }
};

// NOTES
// if node at i and its children violate heap property
// in this case: value needs to trickle down so that children lower than parents
// template <class T>
// void MaxHeap<T>::heapify_down(int i)
// {
// 	int left = Heap<T>::GetLeftChild(i);
// 	int right = Heap<T>::GetRightChild(i);

// 	// node that is violating heap
// 	// setting it to the largest because we go in assuming heap is correct
// 	// i.e. node i is larger than children
// 	int curr_largest = i;

// 	// compare node i with it's child, if its lower, needs to swap
// 	// set largest to now be either left or right child
// 	if(left < GetSize() && Heap<T>::A[left] > Heap<T>::A[i])
// 	{
// 		curr_largest = left;
// 	}
// 	if(right < GetSize() && Heap<T>::A[right] > Heap<T>::A[curr_largest])
// 	{
// 		curr_largest = right;
// 	}

// 	// swap with child that has greater value (left or right)
// 	// then call heapify_down on child
// 	if(curr_largest != i) { // as in we found that it was violating
// 		Heap<T>::Swap(curr_largest, i);
// 		heapify_down(curr_largest);
// 	}
// }

// // move the node up in the heap if we find it is larger than the parent
// template <class T>
// void MaxHeap<T>::heapify_up(int i)
// {
// 	int parent = Heap<T>::GetParent(i);

// 	if(Heap<T>::A[i] > Heap<T>::A[parent])
// 	{
// 		Heap<T>::Swap(i, parent);
// 		heapify_up(parent);
// 	}
// }

// template <class T>
// void MaxHeap<T>::Insert(int i)
// {
// 	Heap<T>::A.push_back(i);

// 	// need to call heapify_up to satisfy heap property
// 	// to do that, need index
// 	// index will be the size of vector - 1 as we've just added a new element
// 	int index = GetSize() - 1;
// 	heapify_up(index);
// }

// remove element at root
// template <class T>
// void MaxHeap<T>::Pop()
// {
// 	// replace root of heap with last element of vector
// 	Heap<T>::A[0] = Heap<T>::A.back(); // return last element of vector
// 	Heap<T>::A.pop_back(); // remove last element of vector

// 	// heapify down since we just move child to root
// 	heapify_down(0);
// }

// return element at root
// template <class T>
// int MaxHeap<T>::Top() {
// 	return top();
// }
