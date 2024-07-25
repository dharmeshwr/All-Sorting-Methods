#include "sorting_algorithms.h"
#include <algorithm>

// TC : n + n - 1 + n - 2 + n - 3 + n - 4 ... +  2 + 1 = n ( n + 1) / 2  => (n^2 / 2) +  (n / 2) => ~ O(n^2);
// in case of almost sorted array, TC can be reduced to ~ O(n);
void bubbleSort(std::vector<int> &nums)
{
    int n = nums.size();
    for (int i = n; i > 0; i--)
    {
        bool didSwap = false;
        for (int j = 1; j < i; j++)
        {
            if (nums[j] < nums[j - 1]) // changing `<` to `>` will sort in desending order
            {
                std::swap(nums[j], nums[j - 1]);
                didSwap = true;
            }
        }

        if (didSwap == false)
            break;
    }
}
