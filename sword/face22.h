#include "..\head.h"

bool IsPopOrder(const int* pPush, const int* pPop, int nLen) {
    bool possible = false;

    if (pPush != nullptr && pPop != nullptr && nLen > 0) {
        const int *nextPush = pPush;
        const int *nextPop = pPop;

        std::stack<int> stackData;

        while (nextPop - pPop < nLen) {
            while (stackData.empty() || stackData.top() != *nextPop) {
                if (nextPush - pPush == nLen) {
                    break;
                }
                stackData.push(*nextPush);
                nextPush++;
            }
            if (stackData.top() != *nextPop) {
                break;
            }
            stackData.pop();
            nextPop++;
        }

        if (stackData.empty() && nextPop - pPop == nLen) {
            possible = true;
        }

    }
    return possible;
}