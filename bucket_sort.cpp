#include "sorting_algorithms.h"
#include <algorithm>

// TC: O(n^2) in worst case when all the numebr got in a same bucket otherwise O(n + k) where k is number of bucket
// SC: O(n + k)
void bucketSort(std::vector<int> &nums)
{
    int max_val      = *max_element(nums.begin(), nums.end());
    int bucket_count = max_val / 10 + 1;
    std::vector<std::vector<int>> buckets(bucket_count);

    /* in the case of floating point numbers which range from [0, 1], the bucket size will be nums.size() */
    /* and bucket index will be n * nums[i] */
    for (int num : nums)
    {
        buckets[num / 10].push_back(num);
    }

    nums.clear();
    for (auto &bucket : buckets)
    {
        std::sort(bucket.begin(), bucket.end());
        nums.insert(nums.end(), bucket.begin(), bucket.end());
    }
}
