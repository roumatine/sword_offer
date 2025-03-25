#include <cstdio>
#include <iostream>
#include <cstring>

void ReplaceBlank(char str[], int len) {
    if (str == nullptr && len <= 0) {
        return;
    }

    int original_len = 0;
    int num_blank = 0;
    int i = 0;
    while (str[i] != '\0') {
        ++original_len; // 遍历计算原str的长度
        if (str[i] == ' ') {
            ++num_blank; // 统计空格数量
        }
        ++i;
    }

    int new_len = original_len + num_blank * 2; // 新str的长度
    if (new_len > len) {
        return;
    }

    int index_of_original = original_len; // 指向原str的最后一个字符
    int index_of_new = new_len; // 新str的索引
    while (index_of_original >= 0 && index_of_new > index_of_original) {
        if (str[index_of_original] == ' ')
        {
            str[index_of_new --] = '0';
            str[index_of_new --] = '2';
            str[index_of_new --] = '%';
        } else {
            str[index_of_new --] = str[index_of_original]; /// 否则，直接复制
        }
        -- index_of_original;
    }
}