/*
9. Palindrome Number

Given an integer x, return true if x is a
palindrome
, and false otherwise.



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1

*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string num = to_string(x);

        int left = 0;
        int right = num.size() - 1;

        while (left < right)
        {
            if (num[left] != num[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};