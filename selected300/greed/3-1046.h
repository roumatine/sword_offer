#include "..\head.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1)
            return stones[0];
        priority_queue<int> pq;
        int s1, s2;
        for (auto &s : stones) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            s1 = pq.top();
            pq.pop();
            s2 = pq.top();
            pq.pop();
            if (s1 != s2)
                pq.push(s1 - s2);
        }
        return pq.empty() ? 0 : pq.top();
    }
};