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

void dfs(vector<string>& res, vector<string> strs, string& chosen, int pos) {
	if (pos == strs.size()) {
		res.push_back(chosen);
		return;
	}
	string str = strs[pos];
	for (int i = 0; i < str.size(); ++i) {
		char ch = str[i];
		chosen.push_back(ch);
		dfs(res, strs, chosen, pos+1);
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

	vector<string> strs;
	for (auto ch : digits) {
		int num = ch - '0';
		if (um.find(num) != um.end()) { strs.push_back(um[num]); }
	}

	vector<string> res;
	string chosen;
	dfs(res, strs, chosen, 0);

	return res;
}

