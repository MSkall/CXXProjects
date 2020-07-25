#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <fstream>
#include <queue>
#include "heap_template.h"

// MAXHEAP AND MINHEAP VERSION - not working
// void addNumber(MaxHeap<int> lowers, MinHeap<int> highers, int number)
// {
//     if(lowers.GetSize() == 0 || number < lowers.Top())
//     {
//         lowers.Insert(number);
//     } 
//     else
//     {
//         highers.Insert(number);
//     }
// }

// void rebalance(MaxHeap<int> lowers, MinHeap<int> highers)
// {
//     MaxHeap<int> biggerHeap;
//     MinHeap<int> smallerHeap;
//     if(lowers.GetSize() > highers.GetSize())
//     {
//         // lowers is the biggerHeap
//         // if the root of lowers 
//         biggerHeap = lowers;
//         smallerHeap = highers;
//     }
//     else
//     {
//         biggerHeap = highers;
//         smallerHeap = lowers;
//     }

//     // MaxHeap<int> biggerHeap = lowers.GetSize() > highers.GetSize() ? lowers : highers;
//     // MinHeap<int> smallerHeap = lowers.GetSize() > highers.GetSize() ? highers : lowers;

//     if(biggerHeap.GetSize() - smallerHeap.GetSize() >= 2)
//     {
//         smallerHeap.Insert(biggerHeap.Top());
//         biggerHeap.Pop();
//     }

// }

// double getMedian(MaxHeap<int> lowers, MinHeap<int> highers)
// {
//     MaxHeap<int> biggerHeap;
//     MinHeap<int> smallerHeap;
//     if(lowers.GetSize() > highers.GetSize())
//     {
//         // lowers is the biggerHeap
//         // if the root of lowers 
//         biggerHeap = lowers;
//         smallerHeap = highers;
//     }
//     else
//     {
//         biggerHeap = highers;
//         smallerHeap = lowers;
//     }
//     // MaxHeap<int> biggerHeap = lowers.GetSize() > highers.GetSize() ? lowers : highers;
//     // MinHeap<int> smallerHeap = lowers.GetSize() > highers.GetSize() ? highers : lowers;

//     if(biggerHeap.GetSize() == smallerHeap.GetSize())
//     {
//         return ((double) biggerHeap.Top() + smallerHeap.Top() ) / 2;
//     }
//     else
//     {
//         return biggerHeap.Top();
//     }
// }

class cmp
{
    public:
        bool operator()(int &n1,int &n2)
        {
            return (n1 > n2);
        }
};
 
std::priority_queue<int,std::vector<int> > lowers;
std::priority_queue<int,std::vector<int>,cmp> highers;
 
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

    std::vector<double> medians = runningMedian(arr);

    for(int i = 0; i < medians.size(); i++)
    {
        std::cout << medians[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}