#include "..\head.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int tot = 0;
        vector<int> cnt(n + 1);

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                cnt[n] ++;
            } else {
                cnt[citations[i]] ++;
            }
        }
        for (int i = n; i >=0; i --) {
            tot += cnt[i];
            if (tot >= i) {
                return i;
            }
        }
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size() - 1;
        int cnt = 0;
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] > i) {
                cnt = i + 1;
            }
        }
        return cnt;
    }
};