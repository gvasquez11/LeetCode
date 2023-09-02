/*
2309. Greatest English Letter in Upper and Lower Case

Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.



Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.


Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        sort(s.begin(), s.end());

        vector<char> allLower;

        for (auto letter : s)
        {
            if (letter >= 97)
                allLower.push_back(letter);
        }

        for (auto letter : allLower)
            cout << letter << endl;

        char maxChar = 'A';
        bool pairs = false;

        for (int i = 0; i < s.size(); i++)
        {
            char letter = s[i];

            if (letter <= 90)
            {
                if (letter >= maxChar)
                {
                    bool found = false;

                    for (int j = 0; j < allLower.size(); j++)
                    {
                        if (letter + 32 == allLower[j])
                        {
                            found = true;
                        }
                    }

                    if (found)
                    {
                        pairs = true;
                        maxChar = letter;
                    }
                }
            }
        }

        string result{maxChar};

        if (!pairs)
            result = "";

        return result;
    }
};