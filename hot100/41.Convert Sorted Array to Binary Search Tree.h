#include "..\head.h"

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        auto dfs = [&](this auto &&dfs, vector<int> &nums, int left, int right) -> TreeNode *
        {
            if (left == right)
            {
                return nullptr;
            }
            int m = left + ((right - left) >> 1);
            return new TreeNode(nums[m], dfs(nums, left, m), dfs(nums, m + 1, right));
        };

        return dfs(nums, 0, nums.size());
    }

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
        int m = left + (right - left) / 2;
        return new TreeNode(nums[m], dfs(nums, left, m), dfs(nums, m + 1, right));
    }
};