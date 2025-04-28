#include "..\head.h"

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k > input.size()) {
        return vector<int>();
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto a : input) {
        pq.push(a);
    }
    vector<int> res;
    while (k --) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}