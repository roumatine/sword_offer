#include "..\head.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        vector<int> res(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return {};
        //初始化一个长度为len的向量ans，所有元素初始值为1
        vector<int> ans(len, 1);
        ans[0] = 1;
        int tmp = 1;
        for (int i = 1; i < len; i++) {
            //从左向右累乘，不包括当前元素
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        //从右向左累乘，不包括当前元素，并与之前的结果相乘
        for (int i = len - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            ans[i] *= tmp;
        }
        return ans;
    }
};

// 原数组：       [1       2       3       4]
// 左部分的乘积：   1       1      1*2    1*2*3
// 右部分的乘积： 2*3*4    3*4      4      1
// 结果：        1*2*3*4  1*3*4   1*2*4  1*2*3*1