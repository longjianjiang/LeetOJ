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

// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
class Solution {
public:
    int longestValidParentheses(string s) {
		int nsize = s.size();
		if (nsize < 2) { return 0; }

		stack<int> stk;
		int left = -1;
		int res = 0;

		for (int i = 0; i < nsize; ++i) {
			auto ch = s[i];
			if (ch == '(') {
				stk.push(i);
			} else {
				if (stk.empty()) {
					left = i;
				} else {
					stk.pop();
					if (stk.empty()) {
						res = max(res, i - left);
					} else {
						res = max(res, i - stk.top());
					}
				}
			}
		}

		return res;
    }
};
