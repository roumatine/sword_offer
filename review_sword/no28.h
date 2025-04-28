#include "..\head.h"

int MoreThanHalfNum_Solution(vector<int> numbers) {
    unordered_map<int, int> unmp;
    int len = numbers.size();
    for (int i = 0; i < len; ++i) {
        unmp[numbers[i]]++;
        if (unmp[numbers[i]] > len / 2) {
            return numbers[i];
        }
    }
    return 0;
}

int more_than_half_num_solution(vector<int> numbers) {
    // 摩尔投票法
    int cnt = 0;
    int num = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        if (cnt == 0) {
            num = numbers[i];
            cnt = 1;
        } else {
            num == numbers[i] ? cnt++ : cnt--;
        }
    }
    cnt = count(numbers.begin(), numbers.end(), num);
    return cnt > numbers.size() / 2 ? num : 0;
}