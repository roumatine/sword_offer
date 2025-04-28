/*
no.37 数字在升序数组中出现的次数
统计一个数字在升序数组中出现的次数
*/

#include "..\head.h"

int GerNumberOfK(vector<int> data, int k) {
    auto pos = equal_range(data.begin(), data.end(), k);
    return pos.second - pos.first;
}

int get_number_of_k(vector<int> data, int k) {
    int low = 0;
    int high = data.size() - 1;
    if (high == -1)
        return 0;

    while (low <= high) {
        int mid = (high - low) / 2;
        if (data[mid] > k) {
            high = mid - 1;
        } else if (data[mid] < k) {
            low = mid + 1;
        } else {
            int cnt = 0;
            cnt ++;
            int index = mid - 1;
            while (index >= 0 && data[index] == k) {
                cnt ++;
                index --;
            }
            index = mid + 1;
            while (index <= data.size() - 1 && data[index] == k) {
                cnt ++;
                index ++;
            }  
            return cnt;
        }
    }
    return 0;
}