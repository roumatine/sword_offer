#include "..\head.h"

int get_firstK(int *data, int len, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid_index = (start + end) / 2;
    int mid_data = data[mid_index];

    if (mid_data == k) {
        if ((mid_index > 0 && data[mid_index - 1] != k) || mid_index == 0) {
            return mid_index;
        } else {
            end = mid_index - 1;
        }
    } else if (mid_data > k) {
        end = mid_index - 1;
    } else {
        start = mid_index + 1;
    }
    return get_firstK(data, len, k, start, end);
}

int get_lastK(int *data, unsigned int len, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid_index = (start + end) / 2;
    int mid_data = data[mid_index];

    if (mid_data == k) {
        if ((mid_index < len - 1 && data[mid_index + 1] != k) || mid_index == len -1) {
            return mid_index
        } else {
            start = mid_index + 1;
        }
    } else if (mid_data < k) {
        start = mid_index + 1;
    } else {
        end = mid_index - 1;
    }
    return get_lastK(data, len, k, start, end);
}

int get_num_of_k(int *data, unsigned int len, int k) {
    int num = 0;
    if (data != nullptr && len > 0) {
        int first = get_firstK(data, len, k, 0, len - 1);
        int last = get_lastK(data, len, k, 0, len - 1);
        
        if (first > -1 && last > -1) {
            num = last - first + 1;
        }
    }
    return num;
}