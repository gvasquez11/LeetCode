/*
500. Keyboard Row

Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".



Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]


Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase).

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> result;

        for (auto word : words)
        {

            int find1 = 0;
            int find2 = 0;
            int find3 = 0;

            for (int i = 0; i < word.size(); i++)
            {
                char letter = (char)tolower(word[i]);

                //.find uses size_t which is an unsigned integer type so it can never be negative
                // if we use int for .find it can still cause problems becuase it
                // can return a value greater than INT_MAX but not npos
                // So the best option is to compare to npos(no position) instead like the following
                if (row1.find(letter) != string::npos)
                    find1++;
                else if (row2.find(letter) != string::npos)
                    find2++;
                if (row3.find(letter) != string::npos)
                    find3++;
            }

            if (find1 == word.size() || find2 == word.size() || find3 == word.size())
                result.push_back(word);
        }

        return result;
    }
};