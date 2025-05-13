#include "..\head.h"

void mergeSort(vector<int> &data, vector<int> &copy, int begin, int end) {
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    int low1 = begin;
    int high1 = mid;
    int low2 = mid + 1;
    int high2 = end;
    int index = begin;
    mergeSort(data, copy, low1, high1);
    mergeSort(data, copy, low2, high2);
    while (low1 <= high1 && low2 <= high2) {
        copy[index++] = data[low1] < data[low2] ? data[low1++] : data[low2++];
    }
    while (low1 <= high1) {
        copy[index++] = data[low1++];
    }
    while (low2 <= high2) {
        copy[index++] = data[low2++];
    }
}