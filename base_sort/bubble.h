#include "..\head.h"

void bubbleSort(vector<int>& a, int n) {
	for (auto i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

void bubbleSort(vector<int>& nums) {

	int len = nums.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len - 1 - i; ++j) {
			if (nums[j] > nums[j + 1]) 
                swap(nums[j], nums[j + 1]);
		}
	}
}

void bubbleSort2(vector<int>& nums) {

	int len = nums.size();
	bool flag = false;
	for (int i = 0; i < len; ++i) {
		flag = false;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (nums[j] > nums[j + 1]) { 
				flag = true;
				swap(nums[j], nums[j + 1]); 
			}
		}
		if (!flag)//说明没有交换，则表明[0,len-i-1]已经是有序的了
			break;
	}
}

