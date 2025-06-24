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