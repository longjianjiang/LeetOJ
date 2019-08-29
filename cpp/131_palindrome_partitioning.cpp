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

// 给定一个字符串，要求返回所有子串都是回文的集合
class Solution {
public:
	bool is_palindrome(string s) {
		if (s.size() < 2) { return true; }

		int left = 0, right = (int)s.size()-1;
		while (left < right) {
			if (s[left] != s[right]) { return false; }
			++left; --right;
		}
		return true;
	}

	// 回溯的方式，穷举所有子串，判断子串是否为回文，分组加入到结果中。
	void helper(string s, vector<string>& chosen, vector<vector<string>>& res, int i) {
		if (i == s.size()) {
			res.push_back(chosen);
			return;
		}

		for (int j = 1; j+i <= s.size(); ++j) {
			string sub = s.substr(i, j);
			if (is_palindrome(sub)) {
				chosen.push_back(sub);
				helper(s, chosen, res, i+j);
				chosen.pop_back();
			}
		}
	}

	vector<vector<string>> partition_backtracking(string s) {
		vector<vector<string>> res;
		vector<string> chosen;
		helper(s, chosen, res, 0);
		return res;
	}

	// 将字符串拆分为两部分，如果前半段是回文，那么对后半段递归找到自己的回文组合，最后拼接。
    vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		
		if (s.empty()) { return res; }
		if (s.size() == 1) { return {{s}}; }
        if (is_palindrome(s)) { res.push_back({s}); }

		for (int i = 1; i < s.size(); ++i) {
			string left = s.substr(0, i);
			if (is_palindrome(left)) {
				string right = s.substr(i);
				vector<vector<string>> parts = partition(right);
				if (!parts.empty()) {
					for (auto arr : parts) {
						vector<string> tmp;
						tmp.push_back(left);
						for (auto str : arr) {
							tmp.push_back(str);
						}
						res.push_back(tmp);
					}
				}
			}
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	string str = "abbab";
	// ["aa", "b"] ["a", "a", "b"]
	auto res = s.partition(str);
	for (auto arr : res) {
		for (auto str : arr) {
			cout << str << ", ";
		}
		cout << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
