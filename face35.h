#include "head.h"

char First_not_repeating_char(const char* pstring) {
    if (pstring == nullptr) {
        return '\0';
    }

    const int table_size = 256;
    unsigned int hashTable[table_size];
    for (unsigned int i = 0; i < table_size; ++i) {
        hashTable[i] = 0;
    }

    const char* pHashKey = pstring;
    while (*(pHashKey) != '\0') {
        hashTable[*(pHashKey++)] ++;
    }
    pHashKey = pstring;

    while(*pHashKey != '\0') {
        if (hashTable [*pHashKey] == 1) {
            return *pHashKey;
        }
        pHashKey ++;
    }
    return '\0';
}