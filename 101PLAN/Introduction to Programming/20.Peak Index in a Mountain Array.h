#include "..\..\head.h"

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 2;
        while (left + 1 < right)
        {
            int mid = left + (right - left) >> 1;
            if (arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }
};