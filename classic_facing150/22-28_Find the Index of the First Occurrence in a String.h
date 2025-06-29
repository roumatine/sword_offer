#include "..\head.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size() + 1, 0);
        vector<int> res;
        for (int j = 2, i = 0; j <= needle.size(); ++j) {
            while (i > 0 && needle[j - 1] != needle[i])
                i = next[i];
            if (needle[j - 1])
                i++;
            next[j] = i;
        }
        for (int i = 0, j = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size()) {
                res.push_back(i - j + 1);
                j = next[j];
            }
        }
        if (res.size() > 0) {
            return res[0];
        }
        return -1;
    }
}; 

int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组
        for(int i = 2, j = 0; i <= m; i++){
            while(j and p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }