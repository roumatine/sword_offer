#include "..\head.h"

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 将nums2中的元素逐一复制到nums1的对应位置，从nums1的有效元素末尾开始
        for (int i = 0; i != n; ++i)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 初始化两个指针i和j分别指向nums1和nums2的最后一个元素
        int i = m - 1;
        int j = n - 1;
        // 初始化一个指针p指向nums1的最后一个位置
        int p = nums1.size() - 1;
        // 当两个数组都有元素未处理完时，比较两个数组当前指针位置的元素，将较大的元素放入nums1的末尾
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[p] = nums1[i];
                i--;
            }
            else
            {
                nums1[p] = nums2[j];
                j--;
            }
            p--;
        }
        // 如果nums2还有元素未处理完，将剩余的元素依次放入nums1的末尾
        while (j >= 0)
        {
            nums1[p] = nums2[j];
            j--;
            p--;
        }
    }
};