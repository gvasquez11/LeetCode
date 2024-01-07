/*
6. Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        int n = s.size();
        int row = 0;
        int direction = 0;

        if (numRows <= 1)
            return s;

        vector<string> words(numRows, "");

        for (int i = 0; i < n; i++)
        {
            words[row].push_back(s[i]);

            if (row == 0)
                direction = 1;
            else if (row == numRows - 1)
                direction = -1;

            row += direction;
        }

        string result = "";
        for (auto word : words)
            result += word;

        return result;
    }
};