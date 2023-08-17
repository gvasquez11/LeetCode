/*
2496. Maximum Value of a String in an Array

The value of an alphanumeric string can be defined as:

The numeric representation of the string in base 10, if it comprises of digits only.
The length of the string, otherwise.
Given an array strs of alphanumeric strings, return the maximum value of any string in strs.



Example 1:

Input: strs = ["alic3","bob","3","4","00000"]
Output: 5
Explanation:
- "alic3" consists of both letters and digits, so its value is its length, i.e. 5.
- "bob" consists only of letters, so its value is also its length, i.e. 3.
- "3" consists only of digits, so its value is its numeric equivalent, i.e. 3.
- "4" also consists only of digits, so its value is 4.
- "00000" consists only of digits, so its value is 0.
Hence, the maximum value is 5, of "alic3".
Example 2:

Input: strs = ["1","01","001","0001"]
Output: 1
Explanation:
Each string in the array has value 1. Hence, we return 1.


Constraints:

1 <= strs.length <= 100
1 <= strs[i].length <= 9
strs[i] consists of only lowercase English letters and digits.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {

        map<char, int> alpha;
        int result = 0;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            alpha[ch]++;
        }

        for (auto word : strs)
        {
            bool isValidWord = false;
            for (auto letter : word)
            {
                if (alpha.count(letter))
                    isValidWord = true;
            }

            if (isValidWord)
            {
                if (word.size() > result)
                    result = word.size();
            }
            else
            {
                int temp = stoi(word);
                if (temp > result)
                    result = temp;
            }
        }

        return result;
    }
};