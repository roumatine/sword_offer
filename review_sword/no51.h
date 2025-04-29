/*
no.51 构建乘积数值
*/

#include "..\head.h"

vector<int> Multiply(const vector<int> &a) {
    vector<int> b;
    for (int i = 0; i < a.size(); ++i) {
        int tmp = 1;
        for (int j = 0; j < a.size(); ++j) {
            if (j != i) 
                tmp *= a[j];
        }
        b.push_back(tmp);
    }
    return b;
}

vector<int> mul_tiply(const vector<int> &a) {
    int len = a.size();
    vector<int> b(len, 0);
    int tmp = 1;
    for (int i = 0; i < len; tmp*=a[i], ++i) {
        b[i] = tmp;
    }
    tmp = 1;
    for (int i = len - 1; i >= 0; tmp *= a[i], --i) {
        b[i] *= b[i]* tmp;
    }
    return b;

}