#include "..\..\head.h"

class Solution {
public:
    bool isPalindrome(string s) {
        string strs;
        for (char ch : s) {
            if (isalnum(ch)) {
                strs += tolower(ch);
            }
        }
        string strs_rev(strs.rbegin(), strs.rend());
        return strs == strs_rev;
    }
};


class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right)
                if (tolower(s[left]) != tolower(s[right]))
                    return false;
                ++left;
                --right;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int diff = 'A' - 'a';
        while (l < r) {
            char left = s[l] >= 'A' && s[l] <= 'Z' ? s[l] - diff : s[l];
            char right = s[r] >= 'A' && s[r] <= 'Z' ? s[r] - diff : s[r];

            if (!(left > 'a' && left < 'z') && !(left > '0' && left < '9')) {
                l++;
                continue;
            }
            if (!(right > 'a' && right < 'z') && !(right > '0' && right < '9')) {
                r--;
                continue;
            }
            if (left != right) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};