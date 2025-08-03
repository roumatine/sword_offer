#include "..\head.h"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        ranges::sort(nums); // sort(nums.begin,nums.end);
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            int x = nums[i];
            if (i && x == nums[i - 1]) // 跳过i重复数字
            {
                continue;
            }
            if (x + nums[i + 1] + nums[i + 2] > 0)
            {
                break;
            }
            if (x + nums[n - 2] + nums[n - 1] < 0)
            {
                continue;
            }
            int j = i + 1;
            int k = n - 1; // 一左一右,最小最大
            while (j < k)
            {
                int sum = x + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({x, nums[j], nums[k]});
                    j += 1;
                    for (j++; j < k && nums[j] == nums[j - 1]; j++)
                        ;
                    for (k--; k > j && nums[k] == nums[k + 1]; k--)
                        ;
                }
            }
        }
    }
};