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
    string minWindow(string s, string t) {
        if (s == t) { return s; }
        if (t.size() > s.size()) { return ""; }
        
		unordered_map<char, int> dict;
		for (char ch: t) {
			if (dict.find(ch) != dict.end()) {
				dict[ch]++;
			} else {
				dict[ch] = 1;
			}
		}
		int left = 0, right = 0;
		int count = t.size();
		int len = INT_MAX;
		string resStr = "";

		while (right < s.size()) {
			if (dict[s[right]] > 0) {
				count--;
			}
			dict[s[right]]--;
			right++;

			while (count == 0) {
				if (right-left < len) {
					len = right-left;
					resStr = s.substr(left, len); 
				}
				dict[s[left]]++;
				if (dict[s[left]] > 0) {
					count++;
				}
				left++;
			}
		}
		return resStr;
    }
};

void unit_test() {
	Solution s;

	
	assert(s.minWindow("a", "b") == "");
	assert(s.minWindow("a", "aa") == "");
	assert(s.minWindow("bdab", "ab") == "ab");
	assert(s.minWindow("ab", "a") == "a");
	assert(s.minWindow("bbaa", "aba") == "baa");
}

int main(){
	unit_test();

	 return 0;
}
