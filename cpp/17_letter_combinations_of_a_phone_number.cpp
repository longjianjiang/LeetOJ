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
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

// [ref](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/hui-su-by-deeplcz-ymye/)
class Solution {
public:
	void helper(vector<string>& res, vector<string> strs, string& chosen, int index) {
		if (strs.size() == index) { 
			res.push_back(chosen);
			return;
		}
		string str = strs[index];
		for (int i = 0; i < str.size(); ++i) {
			chosen.push_back(str[i]);
			helper(res, strs, chosen, index+1);
			chosen.pop_back();
		}
	}

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return {}; }
		unordered_map<int, string> um;
		um[2] = "abc";
		um[3] = "def";
		um[4] = "ghi";
		um[5] = "jkl";
		um[6] = "mno";
		um[7] = "pqrs";
		um[8] = "tuv";
		um[9] = "wxyz";
		
        vector<string> res;
		vector<string> strs;
		for (char ch : digits) {
			strs.push_back(um[ch - '0']);
		}
        string chosen;
		helper(res, strs, chosen, 0);

        return res;
    }
};
