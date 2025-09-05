
#include "..\head.h"
// priority_queue<Type, Container, Functional>;
//               数据类型， 存放容器， 比较方式/优先级
// priority_queue<Type>; 默认容器vector,比较方式是大顶堆 less<type>

// priority_queue<int, vector<int>, greater<int>> q;
// 小顶堆

// priority_queue<int, vector<int>, less<int>> q;
// 大顶堆

// priority_queue<int> a;
// 默认大顶堆

// pair
int main()
{
    priority_queue<pair<int, int>> a;
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    a.push(d);
    a.push(c);
    a.push(b);
    while (!a.empty())
    {
        cout << a.top().first << ' ' << a.top().second << endl;
        a.pop();
    }
}
