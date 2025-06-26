#include "..\..\head.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> unmp1;
        unordered_map<string, char> unmp2;
        
        int n = pattern.size();
        int m = s.size();
        int start = 0;
        int end = 0;
        char ch;
        string word;
        for (int i = 0; i < n; ++i) {
            // 单词起点已经到达边界，说明s中的单词遍历完了
            // 而pattern的字符还有，字符数量多余单词数，不匹配
            if (start >= m)
                return false;
            // End右移直到到达s边界或者分割的空格
            while (end < m && s[end] != ' ') {
                end++;
            }
            word = s.substr(start, end - start); // 截取单词
            ch = pattern[i]; // 获取当前字符
            if ((unmp1.count(ch) && unmp1[ch] != word) ||
                (unmp2.count(word) && unmp2[word] != ch)) {
                    return false;
                } // 字符与单词没有一一映射：即字符记录的映射不是当前单词或单词记录的映射不是当前字符
            // 更新映射，已存在的映射更新后仍然是不变的；不存在的映射将被加入
            unmp1[ch] = word;
            unmp2[word] = ch;
            // 更新单词区间，起点为当前终点的下一个位置；终点初始与起点相同
            start = end + 1;
            end = start;
        }
        return start == m + 1;
    }
};