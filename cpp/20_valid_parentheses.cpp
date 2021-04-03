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
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/

class Solution {
public:
    bool isValid(string s) {
		int nsize = s.size();
		if (nsize < 2) { return false; }

		stack<char> stk;
		for (auto ch : s) {
			if (ch == '(' || ch == '[' || ch == '{') {
				stk.push(ch);
			} else {
				// case ')'
                if (stk.empty()) { return false; }

				char top = stk.top(); stk.pop();
				if (ch == ')') {
					if (top != '(') { return false; }
				}
				if (ch == ']') {
					if (top != '[') { return false; }
				}
				if (ch == '}') {
					if (top != '{') { return false; }
				}
			}
		}

		// case '(('
		return stk.empty();
    }
};
