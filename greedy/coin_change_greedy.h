#include "..\head.h"

int coin_change_greedy(vector<int> &coins, int amt) {
    int i = coins.size() - 1;
    int count = 0;
    // 循环进行贪心选择，直到无剩余金额
    while (amt > 0) {
        // 找到小于且最接近剩余金额的硬币
        while (i > 0 && coins[i] > amt) {
            i --;
        }
        amt -= coins[i];
        count ++;
    }
    return amt == 0 ? count : -1;
}