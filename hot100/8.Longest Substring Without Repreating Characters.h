#include "..\head.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int ans = 0, left = 0;
        unordered_map<char, int> unmp;
        for (int right = 0; right < n; ++right) // 枚举右端点
        {
            char c = s[right];  // 字符放入数值
            unmp[c]++;          // 字符出现次数+1
            while (unmp[c] > 0) // 窗口内有重复字母
            {
                unmp[s[left]]--; // 移除窗口左端点字母
                left++;          // 缩小窗口
            }
            ans = max(ans, right - left + 1); // 更新窗口长度最大值
        }
        return ans;
    }

    int lengthOfLongestSubstring_wid(string s)
    {
        int n = s.length();
        int ans = 0, left = 0;
        unordered_set<char> st; // 维护从下标 left 到下标 right 的字符
        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            while (st.contains(c))
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(c);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};