#include "..\head.h"

string minNumber(vector<int> numbers) {
    vector<string> tmp;
    for (auto num : numbers) {
        tmp.push_back(to_string(num));
    }
    sort(tmp.begin(), tmp.end(), [](string a, string b) {
        return a + b < b + a; 
    });
    string res;
    for (auto &t : tmp) {
        res += t;
    }
    return res;
}