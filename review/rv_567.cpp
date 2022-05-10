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
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
*/

class Solution {
public:
	// 1> s1全排列，依次查看是否包含；
	// 2> 哈希表+滑动窗口；
    bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) { return false; }

		unordered_map<char, int> um;
		for (auto ch : s1) {
			um[ch]++;
		}
		int cnt = um.size();
		int l = 0, r = 0;

		while (r < s2.size()) {
			auto ch = s2[r];
			if (um.find(ch) != um.end()) {
				--um[ch];
				if (um[ch] == 0) {
					--cnt;
					if (cnt == 0) { return true; }
				}
			}
			++r;
			// move window
			if (r - l == s1.size()) {
				auto ch = s2[l];
				if (um.find(ch) != um.end()) {
					um[ch]++;
					if (um[ch] == 1) {
						++cnt;
					}
				}
				++l;
			}
		}

		return false;
    }
};
