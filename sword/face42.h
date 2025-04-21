#include "..\head.h"


void reverse(char *pbegin, char *pend) {
    if (pbegin == nullptr || pend == nullptr) {
        return;
    }
    while(pbegin < pend) {
        char tmp = *pbegin;
        *pbegin = *pend;
        *pend = tmp;

        pbegin++;
        pend--;
    }
}

char *Reverse_sentence(char *pdata) {
    if (pdata == nullptr) {
        return nullptr;
    }
    char *pbegin = pdata;
    char *pend = pdata;
    while (*pend != '\0') {
        pend++;
    }
    pend --;
    reverse(pbegin, pend);
    pbegin = pend = pdata;
    while (*pbegin != '\0') {
        if (*pbegin == ' ') {
            pbegin++;
            pend++;
        } else if (*pend == ' ' || *pend == '\0') {
            reverse(pbegin, pend - 1);
            pbegin = ++pend;
        } else {
            pend++;
        }
    }

}