#include "..\head.h"

void GetLeastNumsSolution1(int *input, int n, int *output, int k) {
    if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0) {
        return;
    }

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
            index = Partition(input, n, start, end);
        } else {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }
    for (int i = 0; i < k; ++i) {
        output[i] = input[i];
    }
}


typedef multiset<int, std::greater<int>> intSet;
typedef multiset<int, std::greater<int>>::iterator SetIterator;

void GetLeasetNumsSolutsion2(const vector<int>& data, intSet& leastNums, int k) {
    leastNums.clear();
    if (k < 1 || data.size() < k) {
        return;
    }

    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); ++iter) {
        if (leastNums.size() < k) {
            leastNums.insert(*iter);
        } else {
            SetIterator iterGreatest = leastNums.begin();
            if (* iter > *(leastNums.begin())) {
                leastNums.erase(iterGreatest);
                leastNums.insert(*iter);
            }
        }
    }
}


