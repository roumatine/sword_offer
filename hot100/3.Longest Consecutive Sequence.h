#include "..\head.h"

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto num : st)
        {
            if (st.contains(num - 1)) // s.find(num - 1) != s.end()
            {
                continue;
            }
            int Nums = num + 1;
            while (st.contains(Nums)) // s.find(Nums) != s.end()
            {
                Nums++;
            }
            ans = max(ans, Nums - num);
        }
        return ans;
    }

    int longestConsecutive_fix(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end()); // 遍历哈希集合
        for (int x : st)                                 // 遍历哈希集合
        {
            if (st.contains(x - 1))
            {
                continue;
            }
            // x 是序列的起点
            int y = x + 1;
            while (st.contains(y))
            { // 遍历哈希集合
                y++;
            }
            // 循环结束后，y-1 是最后一个在哈希集合中的数
            ans = max(ans, y - x); // 循环结束后，y-1 是最后一个在哈希集合中的数
            if (ans * 2 >= nums.size())
            {
                break;
            }
        }
        return ans;
    }
};