#include "..\head.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int cnt_s[128]{};
        int cnt_t[128]{};
        for (char c : t)
        {
            cnt_t[c]++;
        }

        int n = s.size();
        int ans_left = -1;
        int ans_right = n;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            cnt_s[s[right]]++;
            while (is_cover(cnt_s, cnt_t))
            {
                if (right - left < ans_right - ans_left)
                {
                    ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--;
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
    bool is_cover(int cnt_s[], int cnt_t[])
    {
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        return true;
    }
};