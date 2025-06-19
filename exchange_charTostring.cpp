#include "head.h"

int main() {
// a. string to const char*
    string s = "abc";
    const char *c_s = s.c_str();

// b. const char* to string
    const char *c_s_back = "abcd";
    string s(c_s_back);

// c. string to char*
    string str = "abcde";
    char *c;
    const int len = str.length();
    c = new char[len + 1];
    strcpy(c, str.c_str());

// d. char* to string
    char *c = "abcdef";
    string s(c);

// e. const char* to char*
    const char* cpc = "abc";
    char * cp = new char[strlen(cpc) + 1];
    strcpy(cp, cpc);

// f. char* to const char* 
    char* pc = "abc";
    const char* cpc = pc;
}