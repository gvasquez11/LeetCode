/*

1512. Number of Good Pairs

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.



Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {

        // forumla for pairs n*(1-n)/2

        int numOfPairs = 0;
        unordered_map<int, int> myMap;

        for (auto num : nums)
            myMap[num]++;

        for (auto key : myMap)
        {
            int n = key.second;
            numOfPairs += n * (n - 1) / 2;
        }

        return numOfPairs;
    }
};

// Second method without pairs formula
// 0ms O(n) time

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int numOfPairs = 0;
        unordered_map<int, int> myMap;

        for (auto num : nums)
        {
            if (myMap.count(num))
            {
                numOfPairs += myMap[num];
            }
            myMap[num]++;
        }

        return numOfPairs;
    }
};