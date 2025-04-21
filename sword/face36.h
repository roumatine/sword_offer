#include "..\head.h"

int inverse_pairs(int *data, int length) {
    if (data == nullptr || length <= 0) {
        return 0;
    }
    int *copy = new int[length];
    for (int i = 0; i < length; i++) {
        copy[i] = data[i];
    }
    int count = inverse_pairs_core(data, copy, 0, length - 1);
    delete[] copy;
    return count;
}

int inverse_pairs_core(int *data, int *copy, int start, int end) {
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }
    int mid = start + (end - start) / 2;
    int left = inverse_pairs_core(copy, data, start, mid);
    int right = inverse_pairs_core(copy, data,mid + 1, end);
    int i = start + mid;
    int j = end;
    int index_copy = end;
    int count = 0;
    while (i >= start && j >= mid + start + 1) {
        if (data[i] > data[j]) {
            copy[index_copy--] = data[i--];
            count += j - mid - start;
        } else {
            copy[index_copy--] = data[j--];
        }
    }
    
    for(; i >= start; --i)
    copy[index_copy--] = data[i];

    for(; j >= start + mid + 1; --j)
        copy[index_copy--] = data[j];

    return left + right + count;

}