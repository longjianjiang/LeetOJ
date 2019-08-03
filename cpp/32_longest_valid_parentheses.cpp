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

// 给定字符串，求字符串中有效括号子串的最大长度；
// 开始是想着遍历一次，手动记录括号的左右关系，发现这种方式导致代码很长。可以借助栈来进行简化左右的关系。
// 额外定义一个left初始化为-1，left表示`(`的有效位置，这样就可以解决`(()())`case；
// 遍历，当左时，入栈操作。右时，判断栈是否为空，也就是前面是否还有左；
// 出栈。判断栈是否为空，取left或者当前最右的左括号索引，与i进行计算当前子串大小。
class Solution {
public:
    int longestValidParentheses_stack(string s) {
		if (s.size() < 2) { return 0; }

		int res = 0, left = -1;
		stack<int> stk;

		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				s.push(i);
			} else {
				if (s.empty()) {
					left = i;
				} else {
					s.pop();
					if (s.empty()) {
						res = max(res, i - left); // case "()"
					} else {
						res = max(res, i - stk.top());
					}
				}
			}
		}
		return res;
    }

	// 使用dp，dp[i]表示字符串从0开始到i-1的最长字串。
	// s[i-1]为`)`，此时分两种情况：
	// 1> s[i-2] 为`(`, 此时dp[i] = dp[i-2] + 2; 也就是类似"()"这种case。
	// 2> s[i-2] 为`)`, 这种情况需要判断，类似"()(())"这种case，
	// prev = i - dp[i-1] - 2; 当s[prev]为'(', dp[i] = dp[i-1] + dp[prev] + 2;
	
	int longestValidParentheses_dp(string s) {
		if (s.size() < 2) { return 0; }
		
		int nsize = s.size(), res = 0;
		vector<int> dp(nsize + 1, 0);

		for (int i = 1; i <= nsize; ++i) {
			if (s[i-1] == ')') {
				if (i-2 < 0) { continue; }
				if (s[i-2] == '(') {
					dp[i] = dp[i-2] + 2;
				} else if (s[i-2] == ')') {
					int prev = i - dp[i-1] - 2;
					if (prev >= 0 && s[prev] == '(') {
						dp[i] = dp[i-1] + dp[prev] + 2;
					}
				}
				res = max(res, dp[i]);
			}
		}
		return res;
	}
};
