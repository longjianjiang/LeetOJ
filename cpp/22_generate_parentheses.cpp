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
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
	有效括号组合需满足：左括号必须以正确的顺序闭合。

	输入：n = 3
	输出：["((()))","(()())","(())()","()(())","()()()"]
*/

// [ref](https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-deeplcz-v9jg/)
class Solution {
public:

	void dfs(vector<string>& res, string& chosen, int leftNum, int n) {
		if (chosen.size() == 2 * n) {
			res.push_back(chosen);
			return;
		}
		if (leftNum + 1 <= n) {
			chosen += "(";
			dfs(res, chosen, leftNum+1, n);
			chosen.pop_back();
		}
		if (chosen.size() - leftNum < leftNum) {
			chosen += ")";
			dfs(res, chosen, leftNum, n);
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
