#include "..\..\head.h"

vector<vector<int>> largeGroupPositions(string S) {
    if (S.size() <= 2)
        return{};
    vector<vector<int>> res;
    int len = S.size();
    int cnt = 0;
    char ch;
    for (int i = 0; i < len; ++i) {
        if (S[i] == S[i+i]) {
            if (S[i+1] == S[i + 2]) {
                cnt = 0;
                ch = S[i];
                while (S[i] == ch) {
                    cnt ++;
                    i++;
                }
                res.push_back({i - cnt, i - 1});
            } else {
                i++;
            }
        } else {
            i++;
        }

    }
    return res;
}