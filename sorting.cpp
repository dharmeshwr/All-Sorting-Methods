#include "sorting_algorithms.h"
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void printVector(vector<int> &nums)
{
    for (auto &num : nums)
    {
        cout << num << " ";
    }
    cout << '\n';
}

auto measureTime(function<void(vector<int> &)> sortFunction, vector<int> &nums)
{
    auto start = high_resolution_clock::now();
    sortFunction(nums);
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    return duration;
}

void printAndSortWithAllFunctions(vector<int> &nums, unordered_map<string, long long> &totalTimes)
{
    cout << "Original array: ";
    printVector(nums);

    vector<pair<string, function<void(vector<int> &)>>> sortFunctions = {
        {"Selection Sort", selectionSort},
        {"Bubble Sort", bubbleSort},
        {"Insertion Sort", insertionSort},
        {"Merge Sort", mergeSort},
        {"Quick Sort", quickSort},
        {"Heap Sort", heapSort},
        {"Radix Sort", radixSort},
        {"Counting Sort", countingSort},
        {"Bucket Sort", bucketSort},
    };

    for (const auto &[name, func] : sortFunctions)
    {
        vector<int> numsCopy = nums;
        auto duration        = measureTime(func, numsCopy);

        cout << name << " result: ";
        printVector(numsCopy);
        cout << "Time Taken: " << duration.count() << " ns\n\n";

        totalTimes[name] += duration.count();
    }
}

int main(int argc, char *argv[])
{
    vector<vector<int>> testCases = {
        {13, 46, 24, 52, 20, 9},
        {1, 2, 3, 4, 5, 6, 7},
        {100, 42, 17, 65, 33, 21},
    };

    unordered_map<string, long long> totalTimes;

    for (auto &nums : testCases)
    {
        printAndSortWithAllFunctions(nums, totalTimes);
        cout << "--------------------------------\n";
    }

    cout << "Total times for each sorting function:\n";
    for (const auto &[name, time] : totalTimes)
    {
        cout << setw(15) << left << name << ": " << time / 1000 << " ms\n";
    }

    return 0;
}
