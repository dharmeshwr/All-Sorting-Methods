#include "sorting_algorithms.h"
#include <algorithm>

int correctPosition(std::vector<int> &nums, int pivot, int start, int end)
{
    int i = start + 1, j = end;
    while (i <= j)
    {
        while (i <= end && nums[i] <= nums[pivot])
        {
            i++;
        }

        while (j >= start && nums[j] > nums[pivot])
        {
            j--;
        }

        if (i < j)
        {
            std::swap(nums[i], nums[j]);
        }
    }

    std::swap(nums[pivot], nums[j]);

    return j;
}

void quickSortHelper(std::vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int pivot    = start;
    int position = correctPosition(nums, pivot, start, end);
    quickSortHelper(nums, start, position - 1);
    quickSortHelper(nums, position + 1, end);
}

void quickSort(std::vector<int> &nums)
{
    quickSortHelper(nums, 0, nums.size() - 1);
}
