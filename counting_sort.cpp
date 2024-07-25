#include "sorting_algorithms.h"
#include <algorithm>

void countingSortHelper(std::vector<int> &nums, int exp, bool isRadix)
{
    int n = nums.size();

    int range, min_val = 0;
    if (!isRadix)
    {
        int max_val = *max_element(nums.begin(), nums.end());
        min_val     = *min_element(nums.begin(), nums.end());
        range       = max_val - min_val + 1;
    }
    else
    {
        range = 10; // For radix sort, we always use base 10
    }

    std::vector<int> count(range, 0);
    std::vector<int> output(n);

    for (int i = 0; i < n; i++)
    {
        int idx = isRadix ? (nums[i] / exp) % 10 : nums[i] - min_val;
        count[idx]++;
    }

    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int idx                = isRadix ? (nums[i] / exp) % 10 : nums[i] - min_val;
        output[count[idx] - 1] = nums[i];
        count[idx]--;
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = output[i];
    }
}

// TC: O(n + k), k is range of nums
// SC: (k)
void countingSort(std::vector<int> &nums)
{
    countingSortHelper(nums, 1, false);
}
