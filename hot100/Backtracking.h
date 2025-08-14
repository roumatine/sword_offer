// 回溯三问：
// 1. 当前操作?  枚举一个path[i]用来记录要填入的字母 枚举一个字母i->全局数组path[i]
// i不是第i个，而是>=i的部分需要枚举
// 2. 子问题? 构造字符串>=i的部分
// 3. 下一个子问题? 构造字符串>= i+1的部分
// -> dfs(i)->dfs(i+1)

// 回溯 1. 子集 2. 排列 3. 组合

// 子集
// 1. 当前操作 枚举第i个数，选或者不选
// 2. 子问题 从下表>=i 的数字重构造子集
// 3. 下一个子问题 从下标>=i+1的数字中构造子集

//
// vector<vector<int>> ans;
// vector<int> path;
// int n = nums.size();
// auto dfs = [&](this auto &&dfs, int i)
// {
//     if (i == n)
//     {
//     }
// };
// dfs(0);
// return ans;

#include "..\head.h"
// 131. 分割回文串
class Solution
{
private:
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();

        auto dfs = [&](this auto &&dfs, int i)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            for (int j = i; j < n; ++j)
            {
                if (isPalindrome(s, i, j))
                {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        auto dfs = [&](this auto &&dfs, int i, int start)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            if (i < n - 1)
            {
                dfs(i + 1, start);
            }

            if (isPalindrome(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};

// 2.组合
// lc22. 括号生成

// 2.1 剪枝
// 设path长为m
// 需要选d = k - m 个数
// 设当前需要从[1,i]这i个数中选
// if i < d
// 最后必无法选出k个数，即不需要继续递归
class Solution
{ // lc77. 组合
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> path; // (k,0);

        auto dfs = [&](this auto &&dfs, int i)
        {
            if (k == path.size())
            {
                ans.push_back(path);
                return;
            }
            for (int j = i; j >= (k - path.size()); j--)
            {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };
        dfs(n);
        return ans;
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto &&dfs, int i) -> void
        {
            int d = k - path.size();
            if (d == 0)
            {
                ans.push_back(path);
                return;
            }
            if (i > d)
            {
                dfs(i - 1);
            }

            path.push_back(i);
            dfs(i - 1);
            path.pop_back();
        };

        dfs(n);
        return ans;
    }
};

// 设还要选d = k - m个数
// 设还要选和为t的数字
// 初始值n 每选一个数字j就把t减小j

// 剪枝 1. 剩余数字数目不足 i<d
// 2. t < 0
// 3. 剩余数字即使全部选最大之和都不足t

class Solution
{ // lc216. 组合总和III
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto &&dfs, int i, int t) -> void
        {
            int d = k - path.size();

            if (t < 0 || t > (i * 2 - d + 1) * d / 2)
            {
                return;
            }
            if (d == 0)
            {
                ans.push_back(path);
                return;
            }

            for (int j = i; j >= d; j--)
            {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }
};
