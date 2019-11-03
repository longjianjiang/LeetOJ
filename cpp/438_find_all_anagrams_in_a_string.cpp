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

// s: "abab" p: "ab"
// s: "cbaebabacd" p: "abc"
// 1> 遍历s，两层循环，每次遍历p的长度；
// 2> 使用滑动窗口，l和r，cnt标记p的长度，当匹配到一个--cnt，当匹配完成后，尝试++cnt；
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		unordered_map<char, int> dict;
		for (char ch: p) { dict[ch] += 1; }
		int cnt = (int)p.size();
		int l = 0, r = 0;
		vector<int> res;

		while (r < s.size()) {
			if (dict[s[r++]]-- >= 1) { --cnt; } // dict['x'] will be -1
			if (cnt == 0) { res.push_back(l); }
			if (r-l == p.size() && dict[s[l++]]++ >= 0) { ++cnt; }
		}

		return res;
    }
};
