#include "..\..\head.h"

class Solution {
public:
    void SlidingWindow(string s) {
    // 用合适的数据结构记录窗口中的数据，根据具体场景变通
    // 比如说，我想记录窗口中元素出现的次数，就用 map
    // 如果我想记录窗口中的元素和，就可以只用一个 int
        auto window = ...;

        int left = 0, right = 0;
        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            window.add(c);
            // 增大窗口
            right++;

            // 进行窗口内数据的一系列更新
            ...

            //  debug 输出的位置 
            printf("window: [%d, %d)\n", left, right);
            // 注意在最终的解法代码中不要 print
            // 因为 IO 操作很耗时，可能导致超时

            // 判断左侧窗口是否要收缩
            while (window need shrink) {
                // d 是将移出窗口的字符
                char d = s[left];
                window.remove(d);
                // 缩小窗口
                left++;

                // 进行窗口内数据的一系列更新
                ...

            }
        }
    }
}

1、什么时候应该移动 right 扩大窗口？窗口加入字符时，应该更新哪些数据？

2、什么时候窗口应该暂停扩大，开始移动 left 缩小窗口？从窗口移出字符时，应该更新哪些数据？

3、什么时候应该更新结果？