#include "..\..\head.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            int h = min(height[l], height[r]);
            int w = r - l;
            int area = h * w;
            res = max(res, area);
            if (height[l] < height[r]) {
                ++l;
            } else if (height[l] > height[r]) {
                --r;
            }
        }
        return res;
    }
};