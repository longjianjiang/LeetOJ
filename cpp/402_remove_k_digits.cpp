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

// 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
/*
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
		int nsize = num.size();
		if (nsize == 0 || k == 0) { return num; }
		if (nsize == k) { return "0"; }

		string stk;

		for (char ch : num) {
			while (!stk.empty() && ch < stk.back() && k > 0) {
				stk.pop_back();
				--k;
			}
			stk.push_back(ch);
		}

		while (k > 0) {
			stk.pop_back();
			--k;
		}
		while (!stk.empty() && stk[0] == '0') { stk.erase(stk.begin()); }
		return stk.empty() ? "0" : stk;
    }
};
