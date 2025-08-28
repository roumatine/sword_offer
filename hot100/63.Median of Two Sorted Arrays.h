#include "..\head.h"

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        int i = 0, j = (m + n + 1) / 2;
        while (true)
        {
            if (nums1[i] <= nums2[j + 1] && nums1[i + 1] > nums2[j])
            {
                int max1 = max(nums1[i], nums2[j]);
                int min2 = min(nums1[i + 1], nums2[j + 1]);
                return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
            }
            i++;
            j++;
        }
    }

    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        if (a.size() > b.size())
        {
            swap(a, b);
        }
        int m = a.size();
        int n = b.size();
        a.insert(a.begin(), INT_MIN);
        b.insert(b.begin(), INT_MIN);
        a.push_back(INT_MAX);
        b.push_back(INT_MAX);

        int left = 0;
        int right = m + 1;
        while (left + 1 < right)
        {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            if (a[i] <= b[j + 1])
            {
                left = i;
            }
            else
            {
                right = i;
            }
        }

        int i = left;
        int j = (m + n + 1) / 2 - i;
        int max1 = max(a[i], b[j]);
        int min2 = min(a[i + 1], b[j + 1]);
        return (m + n) % 2 ? max1 : (max1 + min2) / 2;
    }
};