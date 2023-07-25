/*
1351. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.



Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/
#include <vector>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {

        int result = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] < 0)
                    result++;
            }
        }

        return result;
    }
};

// Using Binary Search
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {

        int result = 0;

        for (auto row : grid)
        {
            int left = 0;
            int right = row.size() - 1;

            while (left <= right)
            {
                int middle = (left + right) / 2;
                if (row[middle] < 0)
                    right = middle - 1;
                else
                    left = middle + 1;
            }

            result += grid[0].size() - left;
        }
        return result;
    }
};