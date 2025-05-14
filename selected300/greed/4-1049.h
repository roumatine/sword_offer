#include "..\head.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> vec = vector<int>(target + 1, 0);
        long size = stones.size();
        for (int i = 0; i < size; ++i) {
            int s = stones[i];
            for (int j = target; j >= s; --j) {
                vec[j] = max(vec[j], vec[j - s] + s);
            }
        }
        return sum - 2 * vec.back();
    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1);
        for (int stone : stones) {
            for (int i = target; i >= stone; --i) {
                dp[i] = max(dp[i], dp[i - stone] + stone);
            }
        }        
        return sum - 2 * dp[target];
    }
};