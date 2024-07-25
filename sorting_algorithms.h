#pragma once

#include <vector>

void selectionSort(std::vector<int> &nums);
void bubbleSort(std::vector<int> &nums);
void insertionSort(std::vector<int> &nums);
void mergeSort(std::vector<int> &nums);
void quickSort(std::vector<int> &nums);
void heapSort(std::vector<int> &nums);
void radixSort(std::vector<int> &nums);
void countingSort(std::vector<int> &nums);
void bucketSort(std::vector<int> &nums);

void countingSortHelper(std::vector<int> &nums, int exp = 1, bool isRadix = false);
