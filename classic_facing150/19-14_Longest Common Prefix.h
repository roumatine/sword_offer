#include "..\head.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 获取字符串数组的大小
        int n = strs.size();
        // 获取第一个字符串的长度，初始假设它为最长公共前缀
        int m = strs[0].size();
        for (int i = 0; i < m; i++) {
            // 遍历字符串数组中的其他字符
            for (int j = 1; j < n; j++) {
                // 获取当前字符串和前一个字符串，以便比较
                string cur_str = strs[j], pre_str = strs[j - 1];
                // 如果当前字符串或前一个字符串长度不够，或者对应位置的字符不相同
                // 说明已经找到了最长公共前缀的末尾
                if (i >= cur_str.size() || i >= pre_str.size() || cur_str[i] != pre_str[i]) {
                    // 返回当前已匹配的字符串作为最长公共前缀
                    return strs[j].substr(0, i);
                }
            }
        }
        // 如果所有字符串都遍历完毕，没有提前返回，则第一个字符串本身就是最长公共前缀
        return strs[0];
    }
};