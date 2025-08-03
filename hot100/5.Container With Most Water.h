#include "..\head.h"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            height[left] < height[right] ? left++ : right--;
        }
        return ans;
    }
};