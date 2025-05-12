#include "..\..\head.h"

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int i = j - 1;
            int right = j >= heaters.size() ? INT_MAX : heaters[j] - house;
            int left = j < 0 ? INT_MAX : house - heaters[i];
            int cur = min(right, left);
            ans = max(ans, cur);
        }
        return ans;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); ++i) {
            int cur = abs(houses[i] - heaters[j]);
            while (j  < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                j++;
                cur = min(cur, abs(houses[i] - heaters[j]));
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};