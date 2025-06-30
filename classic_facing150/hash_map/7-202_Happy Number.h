#include "..\..\head.h"

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = toSum(slow);
            fast = toSum(fast);
            fast = toSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
private:
    int toSum(int n) {
        int sum = 0;
        while (n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> unset;
        while (n > 1 && !unset.count(n)) {
            unset.insert(n);
            n = getNum(n);
        }
        return n == 1;
    }
private:
    int getNum(int n) {
        int sum = 0;
        while (n) {
            int num = n % 10;
            n /= 10;
            sum += num * num;
        }
        return sum;
    }
};


class Solution {
public:
    /* 分离数字计算各个数字的平方和 */
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    /* 判断一个数是不是快乐数 */
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> set;
        while(1){
            sum = getSum(n);
            /* 判断和是不是1 */
            if(sum == 1)  return true;
            /* 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false */
            if(set.find(sum) != set.end()) return false;
            else set.insert(sum);
            /* 更新n */
            n = sum;
        }
    }
};