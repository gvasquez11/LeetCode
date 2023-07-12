/*
1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.



Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.


Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

*/
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {

        int half = s.size() / 2;
        map<char, int> vowels = {
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1},
            {'A', 1},
            {'E', 1},
            {'I', 1},
            {'O', 1},
            {'U', 1},
        };

        string a = s.substr(0, half);
        string b = s.substr(half);
        int vowelsA = 0;
        int vowelsB = 0;

        for (int i = 0; i < half; i++)
        {
            if (vowels.count(a[i]))
                vowelsA++;
            if (vowels.count(b[i]))
                vowelsB++;
        }

        return vowelsA == vowelsB;
    }
};