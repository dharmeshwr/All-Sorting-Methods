#include "sorting_algorithms.h"
#include <algorithm>

void heapify(std::vector<int> &nums, int n, int i)
{
    int largest = i;         // Initialize largest as root
    int left    = 2 * i + 1; // left = 2*i + 1
    int right   = 2 * i + 2; // right = 2*i + 2

    if (left < n && nums[left] > nums[largest])
    {
        largest = left;
    }

    if (right < n && nums[right] > nums[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}
// TC: O(n * log(n)) [ n ] => for building the heap , [ log n ] => for removing element
void heapSort(std::vector<int> &nums)
{
    int n = nums.size();

    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        std::swap(nums[0], nums[i]);

        // Call heapify on the reduced heap
        heapify(nums, i, 0);
    }
}
