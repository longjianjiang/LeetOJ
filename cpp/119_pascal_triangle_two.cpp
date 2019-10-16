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

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) { return {}; }
        if (rowIndex == 0) { return { 1 }; }
        if (rowIndex == 1) { return {1, 1}; }

        vector<int> res;
        vector<int> last = {1, 1};
        int idx = 2;
        while (idx++ <= rowIndex) {
            res.push_back(1);
            for (int i = 0; i < last.size()-1; ++i) {
                res.push_back(last[i]+last[i+1]);
            }
            res.push_back(1);
            last = res;
            res.clear();
        }

        return last;
    }
};
