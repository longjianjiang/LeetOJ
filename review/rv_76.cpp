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
 输入：s = "ADOBECODEBANC", t = "ABC"
 输出："BANC"
 */

class Solution {
public:
    string minWindow(string s, string t) {
		if (s.empty() || t.empty()) { return ""; }

		unordered_map<char, int> um;
		int cnt = 0, minLen = INT_MAX;
		int left = 0, right = 0;
		auto nsize = s.size();
		string res = "";

		for (auto ch : t) {
			++um[ch];
			++cnt;
		}

		while (right < nsize) {
			auto tmp = s[right];	
			if (um.find(tmp) != um.end() && --um[tmp] >= 0) { --cnt; }
			while (cnt == 0) {
				int len = right - left + 1;
				if (len < minLen) {
					minLen = len;
					res = s.substr(left, len);
				}
				if (um.find(s[left]) != um.end() && ++um[s[left]] > 0) { ++cnt; }
				++left;
			}
			++right;
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}

int main() {
	unit_test();
	return 0;
}
