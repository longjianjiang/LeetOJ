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
    int lengthOfLongestSubstring(string s) {
		if (s.empty()) { return 0; }
		int retVal = 0;
		int pos1 = 0, pos2 = 0;
		unordered_set<char> us;
		while(pos1 < s.size()) {
			if (us.find(s[pos1]) != us.end()) {
				us.erase(s[pos2++]);
			} else {
				us.insert(s[pos1++]);
				if (us.size() > retVal) {
					retVal = us.size(); 
				}
			}
		}
		return retVal; 
    }
};

void unit_test() {
	Solution s;

	assert(s.lengthOfLongestSubstring("dvdf") == 3);
	assert(s.lengthOfLongestSubstring(" ") == 1);
	assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
	assert(s.lengthOfLongestSubstring("aaaaa") == 1);
	assert(s.lengthOfLongestSubstring("pwwkew") == 3);
}

int main() {
	unit_test();

	return 0;
}
