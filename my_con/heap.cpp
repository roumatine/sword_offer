#include "..\head.h"

priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int, vector<int>, less<int> > max_heap;

int main () {
    max_heap.push(1);
    max_heap.push(1);
    max_heap.push(3);
    max_heap.push(2);
    max_heap.push(5);
    max_heap.push(4);
    
    int peek = max_heap.top();

    max_heap.pop();
    max_heap.pop();
    max_heap.pop();
    max_heap.pop();
    max_heap.pop();

    int size = max_heap.size();
    bool isEmpty = max_heap.empty();

    vector<int> vec{1,2,3,4,5};
    priority_queue<int, vector<int>, greater<int>> min_heap(vec.begin(), vec.end());
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}