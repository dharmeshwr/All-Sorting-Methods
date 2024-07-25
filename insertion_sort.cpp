#include "sorting_algorithms.h"
#include <algorithm>

// TC: 1 + 2 + 3 + 4 + 5 + 6 ... + n = n (n + 1) / 2 => => (n^2 / 2) +  (n / 2) => ~ O(n^2)
// In best case, there will be no swap so TC will be reduced to ~ O(n);
void insertionSort(std::vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 0 && nums[j] < nums[j - 1])
        {
            std::swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}
