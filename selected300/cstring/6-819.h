#include "..\..\head.h"


// class Solution {
// public:
//     string mostCommonWord(string paragraph, vector<string>& banned) {
//         unordered_set<string> bannedset;
//         for (auto &word : banned) {
//             bannedset.emplace(word);
//         }
//         int maxFrequency = 0;
//         unordered_map<string, int> frequency;
//         string word;
//         int len = paragraph.size();
//         for (int i = 0; i <= len; ++i) {
//             if (i < len && isalpha(paragraph[i])) {
//                 word.push_back(tolower(paragraph[i]));
//             } else if (word.size() > 0) {
//                 if (!bannedset.count(word)) {
//                     frequency[word] ++;
//                     maxFrequency = max(maxFrequency, frequency[word]);
//                 }
//                 word = "";
//             }
//         }
//         string mostCommon = "";
//         for (auto &[word, fre] : frequency) {
//             if (fre == maxFrequency) {
//                 mostCommon = word;
//                 break;
//             }
//         }
//         return mostCommon;
//     }
// };


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string word;
        int len = paragraph.size();
        int max = 1;
        unordered_map<string, int> unmp;
        for (auto p : paragraph) {
            if (p >= 'A' && p <= 'Z') {
                word += p + 'a' - 'A';
            } else if (p >= 'a' && p <= 'z') {
                word += p;
            } else if (word != "") {
                if (find(banned.begin(), banned.end(), word) == banned.end()) {
                    unmp[word] += 1;
                }
                word = "";
            }
        }
        for (auto a : unmp) {
            if (max <= a.second) {
                max = a.second;
                word = a.first;
            }
        }
        return word;
    }
};