#include "..\..\head.h"

class Solution {
public:
    bool validPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;
        while (low < high) {
            char c1 = s[low];
            char c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return valiPalidrome(s, low, high - 1) || 
                    valiPalidrome(s, low + 1, high);
            }
        }
        return true;
    }

    bool valiPalidrome(string s, int low, int high) {
        for (int i = low, j = high; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};