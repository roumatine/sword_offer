#include "..\head.h"

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int n = s.size();
        int i = n - 1;

        // 从后到前遍历字符串
        while (i >= 0) {
            // 跳过空格，找到单词的起始位置
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            // 查找单词的结束位置
            int end = i;
            while (i >= 0 && s[i] != ' ') i--;

            // 将当前单词添加到结果字符串中，并附加一个空格
            result += s.substr(i + 1, end - i) + ' ';
        }
        // 删除结果字符串末尾的多余空格
        if (!result.empty()) result.pop_back();
        return result;
    }
};