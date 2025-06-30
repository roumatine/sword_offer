#include "..\..\head.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> unmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (unmp.count(num) && i - unmp[num] <= k) {
                return true;
            }
            unmp[num] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> unmp;
        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            if (unmp.contains(a) && i - unmp[a] <= k) {
                return true;
            }
            unmp[a] = i;
        }
        return false;
    }
};


// 滑动窗口
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (!st.insert(nums[i]).second) { // st 中有 nums[i]
                return true;
            }
            if (i >= k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};