#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <fstream>
#include <queue>
#include "heap_template.h"

// MAXHEAP AND MINHEAP VERSION
double addNumber(Heap<int>& lowers, Heap<int>& highers, int number, double& m)
{
    int lsize = lowers.GetSize();
    int hsize = highers.GetSize();

    // if they are the same size
    // just decide which side of the median number will be added to
    if(lsize == hsize)
    {
        if(number < m)
        {
            lowers.Insert(number);
            return lowers.Top();
        }
        else
        {
            highers.Insert(number);
            return highers.Top();
        }
    }

    // rebalance
    // if they are different sizes, the median is the average of tops of both
    // if lowers is bigger...
    if(lsize > hsize)
    {
        // need to add number to lowers
        // extract top of lowers and add to highers
        if(number < m)
        {
            if(lowers.GetSize() != 0)
            {
                highers.Insert(lowers.Top());
                lowers.Pop();
            }
            lowers.Insert(number);
        }
        else
        {
            // adding to biggers
            highers.Insert(number);
        }

        return (double(lowers.Top() + highers.Top())) / 2;
    }
    // if highers is bigger
    else
    {
        // need to add to lowers
        if(number < m)
        {
            lowers.Insert(number);
        }
        // need to add to highers
        else
        {
            if(highers.GetSize() != 0)
            {
                lowers.Insert(highers.Top());
                highers.Pop();
            }
            highers.Insert(number);
        }
        return (double(lowers.Top() + highers.Top())) / 2;
    }
}

std::vector<double> continuousMedian(std::vector<int> arr)
{  

    std::vector<double> medians;

    if(arr.size() == 0) return medians;

    Heap<int>* lowers = new MaxHeap<int>();
    Heap<int>* highers = new MinHeap<int>();

    double median = arr[0];
    for(int i = 0; i < arr.size(); i++)
    {
        int number = arr[i];
        median = addNumber(*lowers, *highers, number, median);
        medians.push_back(median);
    }

    delete lowers;
    delete highers;

    return medians;
}

class cmp
{
    public:
        bool operator()(int &n1,int &n2)
        {
            return (n1 > n2);
        }
};
 
// max heap of lower part of numbers
// min heap of upper part of numbers 

// for priority queue, first element is always the greatest
// so to make a min, we need to use comparator -> or std::greater<T>
std::priority_queue<int,std::vector<int> > lowers;
std::priority_queue<int,std::vector<int>,cmp> highers; // cause the smallest element to appear as the top()
 
double getMedian(int number, double &m)
{
    int size1 = lowers.size();
    int size2 = highers.size();

    // if the sizes are the same, determine which heap it goes
    // by comparing the number to the current median (m)
    // if the number is lower than the median, it will go in the lowers
    // median is just whichever heap we added to (since it will be bigger)
    if(size1 == size2)
    {
        if(number < m)
        {
            lowers.push(number);
            m = (double)(lowers.top());
        }
        else
        {
            highers.push(number);
            m = (double)(highers.top());
        }
    }

    // rebalancing...
    // if the lowers size is bigger, we need to rebalance
    // and then we add the new number
    else if(size1 > size2)
    {
        if(number < m)
        {
            highers.push(lowers.top());
            lowers.pop();
            lowers.push(number);
        }
        else
        {
            highers.push(number);
        }
        m = (double)((double)(highers.top() + lowers.top())/2);
    }
    else
    {
        if(number < m)
            lowers.push(number);
        else
        {
            lowers.push(highers.top());
            highers.pop();
            highers.push(number);
        }
        m = (double)((double)(highers.top() + lowers.top())/2);
    }

    // if(lowers.size() != 0)
    // {
    //     std::cout << "lowers.top(): " << lowers.top() << std::endl;
    // }
    // if(highers.size() != 0)
    // {
    //     std::cout << "highers.top(): " << highers.top() << std::endl;
    // }

    return m;
}

std::vector<double> runningMedian(std::vector<int> arr)
{
    std::vector<double> medians;
    double median = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        median = getMedian(arr[i], median);
        medians.push_back(median);
    }

    return medians;
}

int main()
{
    std::vector<int> arr = {1, 2, 10, 5, 28, 7};

    std::cout << "PriorityQueue Version:" << std::endl;
    std::vector<double> medians = runningMedian(arr);

    for(int i = 0; i < medians.size(); i++)
    {
        std::cout << medians[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Heap Version:" << std::endl;
    std::vector<double> medians2 = continuousMedian(arr);

    for(int i = 0; i < medians2.size(); i++)
    {
        std::cout << medians2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}