#include "..\head.h"

void quickSort(vector<int>& a, int low, int high) {
	if (low >= high)		// 结束标志
		return;
	int first = low;		// 低位下标
	int last = high;		// 高位下标
	int key = a[first];		// 设第一个为基准

	while (first < last)
	{
		// 从后往前走，将比第一个小的移到前面
		while (first < last && a[last] > key)
			last--;
		if (first < last)
			a[first++] = a[last];

		//从前往后走， 将比第一个大的移到后面
		while (first < last && a[first] <= key)
			first++;
		if (first < last)
			a[last--] = a[first];
	}

	a[first] = key;
	// 前半递归
	quickSort(a, low, first - 1);
	// 后半递归
	quickSort(a, first + 1, high);
	
}


quickSort(A, 0,A.size()-1);
	for (auto a : A) {
		cout << a << endl;
	}
