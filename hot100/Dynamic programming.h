#include "..\head.h"

// 198 House Robber
// 自顶向下计算 = 记忆化搜索
// 自底向上算 = 递推

// 1:1翻译成递推 { dfs-> f 数组 ; 递归 -> 循环; 递归边界 -> 数组初始值};
//  dfs(i) = max(dfs(i - 1), dfs(i - 2) + nums[i]);
//  f[i] = max(f[i - 1], f[i - 2] + nums[i]); ---->>i = 0, i = 1 时数组会产生负数下标
// --> f[i + 2] = max(f[i + 1], f[i] + nums[i]);

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        auto dfs = [&](this auto &&dfs, int i) -> int
        {
            if (i < 0)
            {
                return 0;
            }
            if (memo[i] != -1)
            {
                return memo[i];
            }
            return memo[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        };

        return dfs(n - 1);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n + 2);
        for (int i = 0; i < n; i++)
        {
            f[i + 2] = max(f[i + 1], +f[i] + nums[i]);
        }
        return f[n + 1];
    }
    // 空间优化
    int rob(vector<int> &nums)
    {
        int f0 = 0;
        int f1 = 0;
        for (int x : nums)
        {
            int new_f = max(f0 + x, f1);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};

// 选或不选 { 0-1背包 ; 完全背包; 至多/恰好/至少等常见变形}

// 0-1背包:至少有N个物品,第i个物品的体积为w[i]，价值为v[i]，每个物品至多选一个，
// 求体积和不超过capacity时的最大价值和

// 回溯三问 {当前操作? 枚举第i个物品选或不选：不选，剩余容量不变；选，剩余容量减少w[i];
//          子问题? 在剩容量为C时，从前i个物品中得到的最大价值和;
//          下一个子问题? 分类讨论: 不选， 在剩余容量为C时，从前i-1物品中得到的最大价值和;
//                                  选， 在剩余容量为C-w[i]时，从前i-1个物品中得到的最大价值和;}
// dfs(i, c) = max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i]);
// 常见变形 {至多装capacity，求方案数/最大价值和;
//          恰好装capacity， 求方案数/最大/最小价值和;
//          至少装capacity， 求方案数/最小价值和}
// dfs(i, c) = dfs(i - 1, c) + dfs(i - 1, c - w[o]);
// f[i][c] = f[i - 1][c] + f[i - c][c - w[i]];
// f[i + 1][c] = f[i][c] + f[i][c - w[i]];

class Solution
{
public:
    // int zero_one_knapsack(int capacity, int w, int v)
    // {
    //     auto dfs = [&](this auto &&dfs, int i, int capacity)
    //     {
    //         if (i < 0)
    //         {
    //             return 0;
    //         }
    //         if (c < w[i])
    //         {
    //             return dfs(i - 1, c);
    //         }
    //         return max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i]);
    //     };
    //     return dfs(n - 1, capacity);
    // }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        // 整sum 为 p
        // 负数 s - p
        // p - (s - p) = target
        // 2p = s + t
        // p = (s + t) / 2

        int s = reduce(nums.begin(), nums.end() - abs(target));
        if (s < 0 || s % 2)
        {
            return 0;
        }
        int m = s / 2;
        int n = nums.size();
        vector memo(n, vector<int>(m + 1, -1));
        auto dfs = [&](this auto &&dfs, int i, int c) -> int
        {
            if (i < 0)
            {
                return c == 0;
            }
            int &res = memo[i][c];
            if (res != -1)
            {
                return res;
            }
            if (c < nums[i])
            {
                return res = dfs(i - 1, c);
            }
            return res = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
        return dfs(n - 1, m);
    }
};