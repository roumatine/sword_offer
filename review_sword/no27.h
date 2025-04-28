#include "..\head.h"


class Solution {
public :
    vector<string> res;
    void PermutationCore(string &s, int begin, int end) {
        if (begin == end) {
            res.push_back(s);
            return;
        }
        unordered_map<int, int> visited;
        for (int i = begin; i <= end; i++) {
            if (visited[s[i] == 1]) 
                continue;
            swap(s[i], s[begin]);
            PermutationCore(s, begin + 1, end);
            swap(s[i], s[begin]);
            visited[s[i]] = 1;
        }
    }
    vector<string> Permutation(string str) {
        if (str.size() == 0) {
            return vector<string>();
        }
        PermutationCore(str, 0, str.size() - 1);
        sort(res.begin(), res.end());
        return res;
    }
};