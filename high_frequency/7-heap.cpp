#include "..\head.h"

void swap(vector<int> &arr, int a, int b) {
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void adjust(vector<int>& arr, int len, int index) {
    int maxid = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < len && arr[left] < arr[maxid])
        maxid = left;
    if (right < len && arr[right] < arr[maxid])
        maxid = right;
    if (maxid != index) {
        swap(arr, index, maxid);
        adjust(arr, len, maxid);
    }
}

void heapSort(vector<int>& arr, int len) {
    for (int i = (len - 1 - 1) / 2; i >= 0; --i) {
        adjust(arr, len, i);
    }
    for (int i = len - 1; i > 0; --i) {
        swap(arr, 0, i);
        adjust(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {3,4,2,1,5,8,7,6};
    cout << "before: " << endl;
    for (int it : arr)
        cout << it << " ";
    cout << endl;
    heapSort(arr, arr.size());
    cout << "after: " << endl;
    for (int it : arr) {
        cout << it << " ";
    }
    return 0;
}