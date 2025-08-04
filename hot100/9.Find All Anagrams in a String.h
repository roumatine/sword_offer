#include "..\head.h"

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> vec;
        array<int, 26> cnt_p{};
        array<int, 26> cnt_s{};
        for (char c : p)
        {
            cnt_p[c - 'a']++;
        }

        for (int right = 0; right < s.size(); right++)
        {
            cnt_s[s[right] - 'a']++;
            int left = right - p.length() + 1;
            if (left < 0)
            {
                continue;
            }
            if (cnt_s == cnt_p)
            {
                vec.push_back(left);
            }
            cnt_s[s[left] - 'a']--;
        }
        return vec;
    }
};

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int cnt[26]{};
        for (char c : p)
        {
            cnt[c - 'a']++;
        }
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            int c = s[right] - 'a';
            cnt[c]--;
            while (cnt[c] < 0)
            {
                cnt[s[left] - 'a']++;
                left++;
            }
            if (right - left + 1 == p.size())
            {
                ans.push_back(left);
            }
        }
        return ans;
    }
};