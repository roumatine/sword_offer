#include "..\..\head.h"

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int nums1 = stk.top();
                stk.pop();
                int nums2 = stk.top();
                stk.pop();
                if (tokens[i] == "+")
                {
                    stk.push(nums2 + nums1);
                }
                if (tokens[i] == "-")
                {
                    stk.push(nums2 - nums1);
                }
                if (tokens[i] == "*")
                {
                    stk.push(nums2 * nums1);
                }
                if (tokens[i] == "/")
                {
                    stk.push(nums2 / nums1);
                }
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        int result = stk.top();
        stk.pop();
        return result;
    }
};