#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * 每日温度
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int nsize = temperatures.size();
        vector<int> res(nsize, 0);
        stack<int> stk;

        for (int i = 0; i < nsize; ++i) {
            int tmp = temperatures[i];
            while (stk.empty() == false && temperatures[stk.top()] < tmp) {
                int idx = stk.top();
                res[idx] = i - idx;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
