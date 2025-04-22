
#include "..\head.h"
void shellSortCore(vector<int>& nums, int gap, int i) {
	int inserted = nums[i];
	int j;
    //  插入的时候按组进行插入
	for (j = i - gap; j >= 0 && inserted < nums[j]; j -= gap) {
		nums[j + gap] = nums[j];
	}
	nums[j + gap] = inserted;
}

void shellSort(vector<int>& nums) {
	int len = nums.size();
    //进行分组，最开始的时候，gap为数组长度一半
	for (int gap = len / 2; gap > 0; gap /= 2) {
        //对各个分组进行插入分组
		for (int i = gap; i < len; ++i) {
            //将nums[i]插入到所在分组正确的位置上
			shellSortCore(nums,gap,i);
		}
	}

	for (auto a : nums) {
		cout << a << "";
	}

}
