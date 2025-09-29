#include "..\..\head.h"

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int ans = 0, sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (i < k - 1)
            {
                continue;
            }
            ans += sum >= k * threshold;
            sum -= arr[i - k + 1];
        }
        return ans;
    }
};