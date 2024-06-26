/*
2215. Find the Difference of Two Arrays

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.



Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].


Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000


*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {

        vector<vector<int>> result;
        unordered_map<int, int> nums1Map;
        unordered_map<int, int> nums2Map;
        unordered_set<int> used;

        vector<int> notInTwo;
        vector<int> notInOne;

        for (auto num : nums1)
            nums1Map[num]++;

        for (auto num : nums2)
            nums2Map[num]++;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (!(nums2Map.count(nums1[i])) && used.find(nums1[i]) == used.end())
            {
                notInTwo.push_back(nums1[i]);
                used.insert(nums1[i]);
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (!(nums1Map.count(nums2[i])) && used.find(nums2[i]) == used.end())
            {
                notInOne.push_back(nums2[i]);
                used.insert(nums2[i]);
            }
        }

        result.push_back(notInTwo);
        result.push_back(notInOne);

        return result;
    }
};

// Different type of solution.
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> result1;
        vector<int> result2;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (auto num : nums1)
        {
            mp1[num]++;
        }

        for (auto num : nums2)
        {
            if (!mp1.count(num) && mp1[num] <= 1)
                result1.push_back(num);
        }

        for (auto num : nums2)
        {
            mp2[num]++;
        }

        for (auto num : nums1)
        {
            if (!mp2.count(num) && mp2[num] <= 1)
                result2.push_back(num);
        }

        vector<vector<int>> finalResult;
        finalResult.push_back(result2);
        finalResult.push_back(result1);

        return finalResult;
    }
};