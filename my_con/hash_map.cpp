#include "head.h"

unordered_map<int, string> map;

map[12836] = "小哈";
map[15937] = "小啰";
map[16750] = "小算";
map[13276] = "小法";
map[10583] = "小鸭";

string name = map[15937];

map.erase(10583);

for (auto a : map) {
    cout << a.first << "-> " << a.second << endl;
}

for (auto iter = map.begin(); iter != map.end(); iter++) {
    cout << iter->first << "-> " << iter->second << endl;
}