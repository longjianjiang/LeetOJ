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

int lengthOfLongestSubstring(string s) {
	int nsize = s.size();
	if (nsize <= 1) { return nsize; }

	unordered_set<int> us;
	int l = 0, r = 0;
	int res = 0;

	while (r < nsize) {
		char ch = s[r];
		if (us.find(ch) == us.end()) {
			us.insert(ch);
			res = max(res, r-l+1);
		} else {
			while (ch != s[l]) {
				us.erase(s[l]);
				++l;
			}
			++l;
		}
		++r;
	}

	return res;
}

int lengthOfLongestSubstring_sw(string s) {
	int nsize = s.size();
	if (nsize <= 1) { return nsize; }

	unordered_set<int> us;
	int l = 0, r = 0;
	int res = 0;
	while (r < nsize) {
		char ch = s[r];
		if (us.find(ch) != us.end()) {
			us.erase(s[l++]);
		} else {
			us.insert(ch);
			++r;
			if (us.size() > res) {
				res = us.size();
			}
		}
	}

	return res;
}

int lengthOfLongestSubstring(string s) {
	int nsize = s.size();
	if (nsize <= 1) { return nsize; }

	int l = 0, r = 0;
	int res = 0;
	unordered_set<char> us;
	while (r < nsize) {
		char ch = s[r];
		if (us.find(ch) != us.end()) {
			int len = r - l;
			res = max(res, len);
			while (s[l] != ch) {
				us.erase(s[l]);
				++l;
			}
			++l;
		} else {
			us.insert(ch);
		}
		++r;
	}
	res = max(res, r-l);
	return res;
}


void unit_test() {
	assert(lengthOfLongestSubstring("dvdf") == 3);
	assert(lengthOfLongestSubstring(" ") == 1);
	assert(lengthOfLongestSubstring("vabcabcbb") == 3);
	assert(lengthOfLongestSubstring("aaaaa") == 1);
	assert(lengthOfLongestSubstring("pwwkew") == 3);
}

int main() {
	unit_test();

	return 0;
}
