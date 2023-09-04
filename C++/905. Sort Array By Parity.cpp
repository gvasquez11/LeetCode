/*
905. Sort Array By Parity

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.



Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        vector<int> odds;
        vector<int> evens;
        vector<int> result;

        for (auto num : nums)
        {
            if (num % 2 == 0)
                evens.push_back(num);
            else
                odds.push_back(num);
        }

        for (auto val : evens)
            result.push_back(val);

        for (auto val : odds)
            result.push_back(val);

        return result;
    }
};