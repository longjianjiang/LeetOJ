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

	void helper(string left, string right, vector<string>chosen, vector<vector<string>>& res) {
		vector<string> tmp = chosen;
		chosen.push_back(left);
		chosen.push_back(right);
		bool flag = true;
		for (auto str : chosen) {
			if (!is_palindrome(str)) { flag = false; break;}
		}
		if (flag) { res.push_back(chosen); }

		if (left.size() > 2 && is_palindrome(right)) {
			tmp.push_back(right);
			for (int i = 1; i < left.size(); ++i) {
				string nl = left.substr(0, i);
				string nr = left.substr(i);
				helper(nl, nr, tmp, res);
			}
		}
		if (right.size() > 2 && is_palindrome(left)) {
			tmp.push_back(left);
			for (int i = 1; i < right.size(); ++i) {
				string nl = right.substr(0, i);
				string nr = right.substr(i);
				helper(nl, nr, tmp, res);
			}
		}
	}

    vector<vector<string>> partition(string s) {
		if (s.empty()) { return {}; }
		if (s.size() == 1) { return {{s}}; }

		vector<vector<string>> res;
        if (is_palindrome(s)) { res.push_back({s}); }
		vector<string> always;
		for (int i = 0; i < s.size(); ++i) {
			always.push_back(s.substr(i, 1));
		}
		res.push_back(always);
		if (s.size() == 2) { return res; }

		vector<string> chosen;
		for (int i = 1; i < s.size(); ++i) {
			string left = s.substr(0, i);
			string right = s.substr(i);
			helper(left, right, chosen, res);
			chosen.clear();
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
