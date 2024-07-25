#include "sorting_algorithms.h"
#include <algorithm>

// TC : n + n - 1 + n - 2 + n - 3 + n - 4 ... +  2 + 1 = n ( n + 1) / 2  => (n^2 / 2) +  (n / 2) => ~ O(n^2);
void selectionSort(std::vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int mini = nums[i], idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mini > nums[j])
            {
                mini = nums[j];
                idx  = j;
            }
        }
        std::swap(nums[i], nums[idx]);
    }
}
