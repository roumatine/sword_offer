#include "..\head.h"

void quickSort(vector<int> &data, int low, int high) {
    if (low > high)
        return;
    int key = data[low];
    int begin = low;
    int end = high;
    while (begin < end) {
        while (begin < end && data[end] > key) {
            end--;
        }
        if (begin < end)
            data[begin++] = data[end];
        while (begin < end && data[begin] <= key) {
            begin++;
        }
        if (begin < end)
            data[end--] = data[begin];
    }
    data[begin] = key;
    quickSort(data, low, begin - 1);
    quickSort(data, begin + 1, high);
}