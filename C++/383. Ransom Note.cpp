/*
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true


Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (auto val : ransomNote)
            mp1[val]++;

        for (auto val : magazine)
            mp2[val]++;

        for (auto val : mp1)
        {
            if (val.second > mp2[val.first])
                return false;
        }

        return true;
    }
};