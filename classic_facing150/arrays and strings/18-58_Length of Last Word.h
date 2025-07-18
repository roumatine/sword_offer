#include "..\head.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int word_len = 0;
        for (int i = n - 1; i >= 0; i--) {
            // 如果当前字符不为空格，则单词长度加1
            if (s[i] != ' ') {
                word_len++;
            } else if (word_len != 0) {
                // 遇到空白字符且已记录长度就跳过
                break;
            }
        }
        return word_len;
    }
};