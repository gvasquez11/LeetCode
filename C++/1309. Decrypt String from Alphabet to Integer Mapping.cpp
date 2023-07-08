/*
1309. Decrypt String from Alphabet to Integer Mapping

You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.



Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"


Constraints:

1 <= s.length <= 1000
s consists of digits and the '#' letter.
s will be a valid string such that mapping is always possible.

*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string freqAlphabets(string s)
    {

        string result = "";

        unordered_map<string, char> key = {
            {"1", 'a'},
            {"2", 'b'},
            {"3", 'c'},
            {"4", 'd'},
            {"5", 'e'},
            {"6", 'f'},
            {"7", 'g'},
            {"8", 'h'},
            {"9", 'i'},
            {"10#", 'j'},
            {"11#", 'k'},
            {"12#", 'l'},
            {"13#", 'm'},
            {"14#", 'n'},
            {"15#", 'o'},
            {"16#", 'p'},
            {"17#", 'q'},
            {"18#", 'r'},
            {"19#", 's'},
            {"20#", 't'},
            {"21#", 'u'},
            {"22#", 'v'},
            {"23#", 'w'},
            {"24#", 'x'},
            {"25#", 'y'},
            {"26#", 'z'},

        };

        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            if (i + 2 < s.length() && s[i + 2] == '#')
            {
                temp = s.substr(i, 3);

                result += key[temp];
                i += 2;
                temp = "";
            }
            else
            {
                temp = s[i];

                result += key[temp];
                temp = "";
            }
        }

        return result;
    }
};