#include "..\..\head.h"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> unmp1;
        for (int i = 0; i < list1.size(); ++i) {
            unmp1[list1[i]] = i;
        }
        vector<string> ans;
        int index = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (unmp1.count(list2[i]) > 0) {
                int j = unmp1[list2[i]];
                if (i + j  < index) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    index = i + j;
                } else if (i + j == index) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};