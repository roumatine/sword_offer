#include "..\..\head.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        string res = "";
        sort(dictionary.begin(), dictionary.end());
        for (int i = 0; i < n; i++) {
            int j = 0, k = 0;
            int len1 = dictionary[i].size();
            int len2 = s.size();
            while (j < len1 && k < len2) {
                if (dictionary[i][j] == s[k]) {
                    j++;
                    k++;
                } else {
                    k++;
                }
            }
            if (j == len1 && len1 > res.size())
                res = dictionary[i];
        }
        return res;
    }
};