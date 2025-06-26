#include "..\..\head.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) 
            return false;
        int cnt[26] {};
        for (char c : magazine) {
            cnt[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (--cnt[c - 'a' < 0]) {
                return false;
            }
        }
        return true;
    }
}; 


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> unmp(26);
        for (auto ch : magazine) {
            ++unmp[ch];
        }
        for (auto ch : ransomNote) {
            if (unmp[ch] == 0) {
                return false;
            }
            --unmp[ch];
        }
        return true;
    }
};