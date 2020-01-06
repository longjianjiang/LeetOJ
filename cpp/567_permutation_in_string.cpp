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

// 给定s1和s2，要求判断s1的全排列是否是s2的子串；
// 使用滑动窗口，定义一个字典存储s1，遍历s2，统计s1中字符是否在窗口中全部出现即可；
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) { return false; }

		unordered_map<char, int> um;
		for (auto ch: s1) {
			++um[ch];
		}
		int l = 0, r = 0;
		int cnt = um.size();

		while (r < s2.size()) {
			char ch = s2[r];
			if (um.find(ch) != um.end()) {
				--um[ch];
				if (um[ch] == 0) {
					--cnt;
					if (cnt == 0) { return true; }
				}
			}
			++r;
			if (r - l == s1.size()) {
				auto ch = s2[l];
				if (um.find(ch) != um.end()) {
					++um[ch];
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
