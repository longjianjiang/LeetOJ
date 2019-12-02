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

// 给定字符串只包含字母和数字，将字母进行大小写转换，返回所有可能的情况；
// 使用索引进行拼接进行构造，当sub等于size存入数组；
class Solution {
public:
	void dfs(string s, int idx, string sub, vector<string>& res) {
		if (idx == s.size()) {
			res.push_back(sub);
			return;
		}
		if (s[idx] >= '0' && s[idx] <= '9') {
			dfs(s, idx+1, sub+s[idx], res);
		} else {
			dfs(s, idx+1, sub+(char)toupper(s[idx]), res);
			dfs(s, idx+1, sub+(char)tolower(s[idx]), res);
		}
	}

    vector<string> letterCasePermutation(string S) {
		vector<string> res;
		dfs(S, 0, "", res);
		return res;
    }
};
