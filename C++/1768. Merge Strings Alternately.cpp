/*
1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.



Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d


Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

*/

// Solution 1

#include <iostream>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result = "";

        if (word1.size() == word2.size())
        {
            for (int i = 0; i < word1.size(); i++)
            {
                result += word1[i];
                result += word2[i];
            }
        }
        else if (word1.size() < word2.size())
        {
            for (int i = 0; i < word1.size(); i++)
            {
                result += word1[i];
                result += word2[i];
            }
            result += word2.substr(word1.size());
        }
        else if (word1.size() > word2.size())
        {
            for (int i = 0; i < word2.size(); i++)
            {
                result += word1[i];
                result += word2[i];
            }
            result += word1.substr(word2.size());
        }

        return result;
    }
};

// Optimized solution
// O(m+n)

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {

        int len = max(word1.size(), word2.size());
        string result = "";

        for (int i = 0; i < len; i++)
        {
            if (i < word1.size())
                result += word1[i];
            if (i < word2.size())
                result += word2[i];
        }

        return result;
    }
};

// Solution on 8/19/2024

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {

        int minLen = min(word1.size(), word2.size());

        string result = "";

        if (word1.empty())
            return word2;

        if (word2.empty())
            return word1;

        for (int i = 0; i < minLen; i++)
        {
            result += word1[i];
            result += word2[i];
        }

        if (word1.size() != word2.size())
        {
            if (word1.size() > word2.size())
                result += word1.substr(minLen);
            else
                result += word2.substr(minLen);
        }

        return result;
    }
};
