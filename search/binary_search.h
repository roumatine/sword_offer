#include "..\head.h"

int binary_search(vector<int> &n, int target) {
    int i = 0, j = n.size() - 1;
    while (i <= j) {
        int m = i + (j - i)/2;
        if (n[m] < target) {
            i = m + 1;
        } else (n[m] > target) {
            j = m -1;
        } else {
            return m;
        }
    } 
    return -1;
}

int binary_search_LCRO(vector<int> &n, int target) {
    int i = 0, j = n.size() - 1;
    while (i < j) {
        int m = i + (j - i)/2;
        if (n[m] < target) {
            i = m + 1;
        } else (n[m] > target) {
            j = m -1;
        } else {
            return m;
        }
    }
    return -1;
}