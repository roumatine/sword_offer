#include "..\head.h"

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;

int size = max_heap.size();

int peek = max_heap.top();

int size = max_heap.size();
bool isEmpty = max_heap.empty();

vector<int> vec{1, 2, 3, 4, 5};
priority_queue<int, vector<int>, greater<int>> min_heap(vec.begin(), vec.end());

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

int peek()
{
    return max_heap[0];
}

void push(int val)
{
    max_heap.push(val);
    siftUp(max_heap.size() - 1);
}
void siftUp(int i)
{
    while (true)
    {
        int p = parent(i);
        if (p < 0 || max_heap[i] <= max_heap[p])
        {
            break;
        }
        swap(max_heap[i], max_heap[p]);
        i = p;
    }
}

/* 元素出堆 */
void pop()
{
    if (isEmpty)
    {
        throw out_of_range("heap is empty");
    }
    swap(max_heap[0], max_heap[max_heap.size() - 1]);
    max_heap.pop();
    siftDown(0);
}
void siftDown(int i)
{
    while (true)
    {
        int l = left(i), r = right(i), maX = i;
        if (l < max_heap.size() && max_heap[l] > max_heap[maX])
        {
            maX = l;
        }
        if (r < max_heap.size() && max_heap[r] > max_heap[maX])
        {
            maX = r;
        }
        if (maX == i)
        {
            break;
        }
        swap(max_heap[i], max_heap[maX]);
        i = maX;
    }

    /* 构造方法，根据输入列表建堆 */
    // MaxHeap(vector<int> nums) {
    //     // 将列表元素原封不动添加进堆
    //     maxHeap = nums;
    //     // 堆化除叶节点以外的其他所有节点
    //     for (int i = parent(size() - 1); i >= 0; i--) {
    //         siftDown(i);
    //     }
    // }