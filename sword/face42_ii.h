#include "..\head.h"
#include "face42.h"

char *left_rotate_string(char *pstr, int n) {
    if (pstr != nullptr) {
        int nlen = static_cast<int>(strlen(pstr));
        if (nlen > 0 && n > 0 && n < nlen) {
            char *p_first_start = pstr;
            char *p_first_end = pstr + n - 1;
            char *p_second_start = pstr + n;
            char *p_second_end = pstr + nlen - 1;

            reverse(p_first_start, p_first_end);
            reverse(p_second_start, p_second_end);
            reverse(p_first_start, p_second_end);
        }
    }
    return pstr;
}