/*
1773. Count Items Matching a Rule

You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.



Example 1:

Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
Example 2:

Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.


Constraints:

1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey is equal to either "type", "color", or "name".
All strings consist only of lowercase letters.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Solution One - Brute Force
// O(n^2)

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {

        int matches = 0;

        for (int i = 0; i < items.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ruleKey == "color" && j == 1 && items[i][j] == ruleValue)
                    matches++;
                else if (ruleKey == "type" && j == 0 && items[i][j] == ruleValue)
                    matches++;
                else if (ruleKey == "name" && j == 2 && items[i][j] == ruleValue)
                    matches++;
            }
        }

        return matches;
    }
};

// Solution Two - Using unordered_map
// O(n)

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {

        int result = 0;
        unordered_map<string, int> keyMap = {
            {"type", 0},
            {"color", 1},
            {"name", 2}};

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i][keyMap[ruleKey]] == ruleValue)
                result++;
        }

        return result;
    }
};