#include "sorting_algorithms.h"

void merge(std::vector<int> &nums, int start, int mid, int end)
{
    int left = start, right = mid + 1;
    std::vector<int> temp;

    while (left <= mid && right <= end)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left++]);
        }
        else
        {
            temp.push_back(nums[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left++]);
    }

    while (right <= end)
    {
        temp.push_back(nums[right++]);
    }

    for (int i = start; i <= end; i++)
    {
        nums[i] = temp[i - start];
    }
}

void mergeSortHelper(std::vector<int> &nums, int start, int end)
{
    if (start == end)
        return;

    int mid = (start + end) >> 1;

    mergeSortHelper(nums, start, mid);
    mergeSortHelper(nums, mid + 1, end);

    merge(nums, start, mid, end);
}

// TC : O(n*log(n)) [ log(n) ] => for the recursion and [ n ] for the mergeing the arrays
void mergeSort(std::vector<int> &nums)
{
    mergeSortHelper(nums, 0, nums.size() - 1);
}
