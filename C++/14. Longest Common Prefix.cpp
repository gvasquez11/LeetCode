/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string word = strs[0];
        string result = "";

        for (int i = 0; i < word.size(); i++)
        {
            char charToCheck = word[i];
            for (int j = 1; j < strs.size(); j++)
            {
                string wordTemp = strs[j];
                if (charToCheck != wordTemp[i])
                    return result;
            }
            result += charToCheck;
        }

        return result;
    }
};