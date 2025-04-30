/*
数据流中的中位数
*/

#include "..\head.h"

class Solution {
private:
    int cnt = 0;
    priority_queue<int, vector<int>, less<int>> left_big;
    priority_queue<int, vector<int>, greater<int>> right_small;

public:
    void Insert(int num) {
        cnt ++;
        if (cnt % 2 == 1) {
            right_small.push(num);
            left_big.push(right_small.top());
            right_small.pop();
        } else {
            left_big.push(num);
            right_small.push(left_big.top());
            left_big.pop();
        }
    }

    double GetMedian() {
        if (cnt % 2 == 1)
            return left_big.top();
        else 
            return double((left_big.top() + right_small.top()) / 2.0);
    }
};


class solution {
private:
    vector<int> res;
public:
    void Insert(int num) {
        res.push_back(num);
    }
    double GetMedian() {
        sort(res.begin(), res.end());
        int len = res.size();
        if (len % 2 == 0) {
            return (res[len / 2] + res[-1 + len / 2]) / 2.0;
        } else {
            return res[len / 2];
        }
    }
};