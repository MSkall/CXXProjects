#include <iostream>
#include <iomanip>
#include <vector>
#include "heap_template.h"
#include <limits>
#include <fstream>

std::vector<double> runningMedian(std::vector<int> arr)
{
	// max heap for lower half, min heap for upper half

	// if heaps differ in size
	// take max of lower or min of higher (whichever is bigger)
	// if heaps same size -> avg lower max and higher min

	MaxHeap<int> lowers; // max
	MinHeap<int> highers; // min

	std::vector<double> medians;

	return medians;
}

int main()
{
	std::ofstream fout(std::getenv("OUTPUT_PATH"));

    int a_count;
    std::cin >> a_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        std::cin >> a_item;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    std::vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}