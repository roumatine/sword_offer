#include "..\head.h"

int last_remaining(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    unsigned int i = 0;
    list<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }
    list<int>::iterator cur = nums.begin();
    while(nums.size() > 1) {
        for (int i = 0; i < m; i ++) {
            cur ++;
            if (cur == nums.end()) {
                cur = nums.begin();
            }
        }
        list<int>::iterator next = ++cur;
        if (next == nums.end()) {
            next = nums.begin();
        }
        -- cur;
        nums.erase(cur);
        cur = next;
    }
    return *(cur);
}

int LastRemaining(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    int last = 0;
    for (int i = 2; i <= n; i ++) {
        last = (last + m) % i;
    }
    return last;
}