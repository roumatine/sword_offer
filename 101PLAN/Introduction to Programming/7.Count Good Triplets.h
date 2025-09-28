#include "..\..\head.h"

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; i < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(arr[i] - arr[j]) > a)
                    continue; // 提前剪枝
                for (int k = j + 1; k < n; k++)
                {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int n = arr.size(), mx = ranges::max(arr), ans = 0;
        vector<int> s(mx + 2);
        for (int j = 0; j < arr.size(); j++)
        {
            int y = arr[j];
            for (int k = j + 1; k < arr.size(); k++)
            {
                int z = arr[k];
                if (abs(y - z) > b)
                    continue;                     // 不满足就跳过
                int low = max({y - a, z - c, 0}); // 题里明确元素>=0
                int high = min({y + a, z + c, mx});
                // 如果 l > r + 1，s[r + 1] - s[l] 可能是负数
                ans += max(s[high + 1] - s[low], 0); // 就是Ai范围没有交集的情况
            }
            for (int v = y + 1; v < mx + 2; v++)
            {           // 从元素y开始+,因为j向右移动了 i就可以去读取到这个y值了
                s[v]++; // 把y加到cnt数组中,更新所有收到影响的前缀和
            }
        }
        return ans;
    }
};