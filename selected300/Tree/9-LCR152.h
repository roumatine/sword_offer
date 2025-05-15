#include "..\..\head.h"

class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
private:
    bool recur(vector<int> &postorter, int i, int j) {
        if (i >= j) {
            return true;
        }
        int p = i;
        while (postorter[p] < postorter[j])
            ++p;
        int m = p;
        while (postorter[p] > postorter[j])
            ++p;
        return p == j && recur(postorter, i , m - 1) && recur(postorter, m, j - 1);
};


class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        if (postorder.empty())
            return true;
        return verifyTreeOrderCore(postorder, 0, postorder.size() - 1);
    }
    bool verifyTreeOrderCore(vector<int> &postorder, int start, int end) {
        if (start >= end)
            return true;
        int left = start;
        while (left < end && postorder[left] < postorder[end])
            ++left;
        for (int i = left; i < end; ++i) {
            if (postorder[i] <= postorder[end])
                return false;
        }
        return verifyTreeOrderCore(postorder, start, left - 1) && verifyTreeOrderCore(postorder, left, end - 1);
    }
};