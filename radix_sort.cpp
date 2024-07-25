#include "sorting_algorithms.h"
#include <algorithm>

// TC: O(d * (n  + b)), n is number of elements,  d is number of digits in largest number, b is base of number system(b = 10)
// SC: O(n + b)
void radixSort(std::vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end());

    for (int exp = 1; maxi / exp > 0; exp *= 10)
    {
        countingSortHelper(nums, exp, true);
    }
}
