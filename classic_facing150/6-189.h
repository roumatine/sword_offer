#include "..\head.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        n = nums.size();
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            vec[(i + k) % n] = news[i];
        }
        nums.assign(vec.begin(), vec.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};