#include "..\head.h"

void reOderArray(vector<int> &array) {
    vector<int> tmp(array.size(), 0);
    int low = 0;
    for (int i = 0; i < array.size; ++i) {
        if ((array[i] & 1) == 1) {
            tmp[low++] = array[i];
        }
    }
    for (int i = 0; i < array.size; ++i) {
        if ((array[i] & 1) == 0) {
            tmp[low++] = array[i];
        }
    }
    array.assign(tmp.begin(), tmp.end());
}

void reorderArray(vector<int>& array) {
    for (int i = 0; i < array.size(); ++i) {
        for (auto a : array) {
            cout << a << " ";
        }
        cout << endl;
        for (int j = array.size() - 1; j > i; j--) {
            if (array[i] % 2 == 1 && array[j-1] % 2 ==0) {
                swap(array[i], array[j-1]);
            }
        }
    }
}