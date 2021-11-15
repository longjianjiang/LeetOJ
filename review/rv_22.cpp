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
    void dfs(vector<string>& res, string chosen, int left, int n) {
        if (chosen.size() == n * 2) {
            res.push_back(chosen);
            return;
        }
        // left
        if (left + 1 <= n) {
            chosen.push_back('(');
            dfs(res, chosen, left+1, n);
            chosen.pop_back();
        }
        // right
        if (chosen.size() - left < left) {
            chosen.push_back(')');
            dfs(res, chosen, left, n);
            chosen.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n <= 0) { return {}; }

        vector<string> res;
        string chosen;
        dfs(res, chosen, 0, n);

        return res;
    }
};
