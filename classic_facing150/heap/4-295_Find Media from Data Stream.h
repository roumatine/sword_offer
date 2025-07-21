#include "..\..\head.h"

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.size() == right.size())
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian()
    {
        if (left.size() > right.size())
        {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }

private:
    priority_queue<int> left;                          // 最大堆
    priority_queue<int, vector<int>, greater<>> right; // 最小堆
};
