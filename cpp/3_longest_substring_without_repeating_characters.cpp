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
		int nsize = s.size();
        if (nsize <= 1) { return nsize; }

        int l = 0, r = 0;
        int res = 0;
        unordered_set<int> us;
        while (r < nsize) {
            auto ch = s[r];
            if (us.find(ch) == us.end()) {
                us.insert(ch);
            } else {
                res = max(res, r - l);
                while (ch != s[l]) {
                    us.erase(s[l]);
                    ++l;
                }
                ++l;
            }
            ++r;
        }
		// case: "abcd"
        res = max(res, r - l);

        return res;
	}
	// sliding window
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

	// two pointer
	int lengthOfLongestSubstring_tp(string s) {
		if (s.empty()) { return 0; }
		if (s.size() == 1) { return 1; }

		int res = 0;
		int left = 0, right = 0;
		unordered_set<char> us;
		while (right < s.size()) {
			char ch = s[right];
			if (us.find(ch) != us.end()) {
				while (ch != s[left]) {
					us.erase(s[left]);
					++left;
				}	
				++left;
			} else {
				us.insert(ch);
				res = max(res, right-left+1);
			}
			++right;
		}

		return res;
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
