#include "..\..\head.h"

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size());
    }

private:
    TreeNode *dfs(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nullptr;
        }
        int m = left + (right - left) / 2; // 比直接(left+right)/2更安全
        return new TreeNode(nums[m], dfs(nums, left, m), dfs(nums, m + 1, right));
    }
};