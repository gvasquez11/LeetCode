/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> myMap;

        if (s.size() != t.size())
            return false;

        for (auto character : s)
            myMap[character]++;

        for (auto character : t)
        {
            if (!(myMap.count(character)))
                return false;
            else
                myMap[character]--;
        }

        for (auto key : myMap)
        {
            if (key.second > 0)
                return false;
        }

        return true;
    }
};