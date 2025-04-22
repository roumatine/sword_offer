#include "..\head.h"

void selectionSort(vector<int>& a, int n) {
	int minIndex;
	for (int i = 0; i < n; ++i) {
		minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[minIndex]) minIndex = j;
		}
		swap(a[i], a[minIndex]);	
	}
}

void selectSort(vector<int>& nums) {
	int len = nums.size();
	int minIndex = 0;
	for (int i = 0; i < len; ++i) {
		minIndex = i;
		for (int j = i + 1; j < len; ++j) {
			if (nums[j] < nums[minIndex]) minIndex = j;
		}
		swap(nums[i], nums[minIndex]);
	}
}
