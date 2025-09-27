#include "..\head.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> unmp;
        for (int num : nums)
        {
            unmp[num]++;
        }

        for (int num : nums)
        {
            if (unmp[num] == 1)
            {
                return num;
            }
        }
        return -1;
    }

    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            // 对当前数字与累积结果进行异或操作
            // 异或操作具有以下性质：
            // 1. 任何数与0异或，结果仍为其本身：a ^ 0 = a
            // 2. 任何数与自身异或，结果为0：a ^ a = 0
            // 3. 异或运算满足交换律和结合律：a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
            // 因此，数组中所有成对出现的数字经过异或操作后都将被抵消，最终结果就是只出现一次的数字
            ans ^= num;
        }
        return ans;
    }
};