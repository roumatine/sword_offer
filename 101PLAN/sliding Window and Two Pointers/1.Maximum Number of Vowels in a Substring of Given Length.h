#include "..\..\head.h"

// 定长滑动窗口
// 窗口右端点在i时，由于窗口为k，所以左端点在 i - k + 1
// 三步走 ： 入 - 更新 - 出
// 1. 入：下标为i的元素进入窗口，更新相关统计量。如果窗口i-k+1<0则未形成第一个窗口，重复1
// 2. 更新： 更新答案。一边是更新最大\最小值
// 3. 出：下标为 i-k+1的元素离开窗口，更新相关统计量为下一个循环做准备

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                cnt++;
            }
            int left = i - k + 1;
            if (left < 0)
            {
                continue;
            }

            ans = max(ans, cnt);

            char out = s[left];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u')
            {
                cnt--;
            }
        }
        return ans;
    }

    // 优化
    int maxVowels(string s, int k)
    {
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                cnt++;
            }

            int left = i - k + 1;
            if (left < 0)
            {
                continue;
            }

            ans = max(ans, cnt);
            if (ans == k)
            {
                break;
            }

            char out = s[left];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u')
            {
                cnt--;
            }
        }
        return ans;
    }
};