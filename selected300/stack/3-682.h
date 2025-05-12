#include "..\..\head.h"

// class Solution {
// public:
//     int calPoints(vector<string>& operations) {
//         vector<int> stk;
//         for (auto& op : operations) {
//             switch (op[0])
//             {
//             case '+':
//                 stk.push_back(stk[stk.size() - 2] + stk.back());
//                 break;
//             case 'D':
//                     stk.push_back(st.back() * 2);
//                     break;
//                 case 'C':
//                     stk.pop_back();
//                     break;
//                 default:
//                     stk.push_back(stoi(op));
//             }
//         }
//         return reduce(stk.begin(), stk.end());
//     }
// };

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0;
        vector<int> points;
        for (auto &op : ops) {
            int n = points.size();
            switch (op[0]) {
                case '+':
                    ret += points[n - 1] + points[n - 2];
                    points.push_back(points[n - 1] + points[n - 2]);
                    break;
                case 'D':
                    ret += 2 * points[n - 1];
                    points.push_back(2 * points[n - 1]);
                    break;
                case 'C':
                    ret -= points[n - 1];
                    points.pop_back();
                    break;
                default:
                    ret += stoi(op);
                    points.push_back(stoi(op));
                    break;
            }
        }
        return ret;
    }
};