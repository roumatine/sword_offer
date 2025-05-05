
#include "..\..\head.h"

bool canPlaceFlowers(vector<int> & flowerbed, int n) {
    int len = 1;
    int ans = 0;
    for (auto &i : flowerbed) {
        if (i) {
            ans += (len - 1) / 2;
            len = 0;
        } else {
            ++len;
        }
    }
    ans += (len) / 2;
    return ans >= n;
}