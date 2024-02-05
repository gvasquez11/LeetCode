/*
1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.



Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.


Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].

*/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <stack>

using namespace std;

// Recursive
class Solution
{
public:
    int goodNodes(TreeNode *root, int maxNum = INT_MIN)
    {

        if (!root)
            return 0;

        if (root->val >= maxNum)
            return 1 + goodNodes(root->left, max(root->val, maxNum)) + goodNodes(root->right, max(root->val, maxNum));

        return 0 + goodNodes(root->left, max(root->val, maxNum)) + goodNodes(root->right, max(root->val, maxNum));
    }
};

// Iterative (Stack)
class Solution
{
public:
    int goodNodes(TreeNode *root)
    {

        stack<pair<TreeNode *, int>> myStack;
        myStack.push({root, root->val});

        int result = 0;

        while (!myStack.empty())
        {
            auto [node, maxVal] = myStack.top();
            myStack.pop();

            if (node->val >= maxVal)
                result++;
            if (node->left)
                myStack.push({node->left, max(node->val, maxVal)});
            if (node->right)
                myStack.push({node->right, max(node->val, maxVal)});
        }

        return result;
    }
};