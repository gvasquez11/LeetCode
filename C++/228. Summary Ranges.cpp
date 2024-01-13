/*
228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b


Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        string temp = "";
        vector<string> result;

        if (nums.empty())
            return result;
        if (nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }

        int front = nums[0];
        int back = nums[1];

        for (int i = 0; i < nums.size(); i++)
        {
            int count = 1;
            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
            {
                back = nums[i + 1];
                i++;
                count++;
            }
            if (count > 1)
            {
                temp = to_string(front) + "->" + to_string(back);
            }
            else
            {
                temp = to_string(front);
            }

            result.push_back(temp);
            temp = "";
            if (i + 1 < nums.size())
                front = nums[i + 1];
            count = 1;
        }

        return result;
    }
};