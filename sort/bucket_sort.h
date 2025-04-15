#include "..\head.h"

void bucket_sort(vector<int> &nums) {
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);
    for (float num : nums) {
        // 输入数据范围为 [0, 1)，使用 num * k 映射到索引范围 [0, k-1]
        int i = num * k;
        buckets[i].push_back(num);
    }
    for (vector<float> &bucket:buckets) {
        // 使用内置排序函数，也可以替换成其他排序算法
        sort(bucket.begin(), bucket.end());
    }
    int i = 0;
    for (vector<float> &bucket:buckets) {
        for(float num:bucket) {
            nums[i++] = num;
        }
    }

}