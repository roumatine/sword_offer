/*
no.64 滑动窗口的最大值
*/

#include "..\head.h"

vector<int> maxInWindows(const vector<int> & nums, unsigned int size) {
    if (size > nums.size() || size == 0 || nums.size() == 0)
        return vector<int>();
    int len = nums.size();
    int cnt = 0;
    vector<int> res;
    priority_queue<int> pq;
    for (int i = 0; i <= len - size; ++i) {
        while (cnt < size) {
            pq.push(nums[i + cnt]);
            cnt ++;
        }
        cnt = 0;
        res.push_back(pq.top());
        while (!pq.empty()) {
            pq.pop();
        }
    }
    return res;
}

vector<int> max_in_windows(const vector<int> & nums, unsigned int size) {
    if (size > nums.size() || size == 0 || nums.size() == 0)
        return vector<int>();
    int len = nums.size();
    vector<int> res;
    deque<int> dq;
    for (int i = 0; i < len; ++i) {
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        while (!dq.empty() && i - dq.front() >= size) {
            dq.pop_front();
        }
        dq.push_back(i);
        if (i + 1 >= size) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}