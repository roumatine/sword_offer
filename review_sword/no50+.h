/*
no.50 数字中重复的数字

*/

#include "..\head.h"

bool duplicate(int nums[], int len, int *dup) {
    unordered_map<int, int> unmp;
    unmp.reserve(len);
    for (int i = 0; i < len; ++i) {
        if (unmp.find(nums[i]) == unmp.end()) {
            unmp.insert({ nums[i], 1});
        } else {
            *dup = nums[i];
            return true;
        }
    }
    return false;
}

bool Duplicate(int numbers[], int length, int *duplicate) {
    vector<bool> res (length, false);
    for (int i = 0; i < length; ++i) {
        if (res[numbers[i]] == false) {
            res[numbers[i]] = true;
        } else {
            duplicate[0] = numbers[i];
            return true;
        }
        
    }
    return false;
}