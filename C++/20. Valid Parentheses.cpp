/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> myStack;

        myStack.push(s[0]);

        for (int i = 1; i < s.size(); i++)
        {
            char check = s[i];
            if (myStack.empty())
                myStack.push(check);
            else if (myStack.top() == '(' && check == ')')
                myStack.pop();
            else if (myStack.top() == '{' && check == '}')
                myStack.pop();
            else if (myStack.top() == '[' && check == ']')
                myStack.pop();
            else
                myStack.push(check);
        }

        return myStack.empty();
    }
};