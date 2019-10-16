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

// 给定逆波兰表达式，操作符放在操作数后面的形式，返回表达式结果。
// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

// 用栈即可。
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) { return 0; }

		unordered_set<string> us = {"+", "-", "*", "/"};
		stack<string> stk;
		int res = 0;
		for (auto token : tokens) {
			if (us.find(token) != us.end()) {
				int right = stoi(stk.top()); stk.pop();
				int left = stoi(stk.top()); stk.pop();
				if (token == "+") {
					res = left+right;
				} else if (token == "-") {
					res = left-right;
				} else if (token == "*") {
					res = left*right;
				} else if (token == "/"){
					res = left/right;
				}
				stk.push(to_string(res));
			} else {
				stk.push(token);
			}
		}

		if (!stk.empty()) { return stoi(stk.top()); }
		
		return res;
    }
};


void unit_test() {
	Solution s;
}

int main() {
	unit_test();
	return 0;
}
