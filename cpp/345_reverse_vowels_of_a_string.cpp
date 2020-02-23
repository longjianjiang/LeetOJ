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

// 给定字符串，倒置其中的元音字母；
// 1> 使用栈；
// 2> two pointer；
class Solution {
public:
    string reverseVowels(string s) {
		unordered_set<char> us = {a, e, i, o, u};
		int nsize = s.size();
		int l = 0, r = s.size()-1;
		while (l < r) {
			while (l < nsize && !isVowel(s[l])) { ++l; }
			while (r >= 0 && !isVowel(s[r])) { --r; }
			if (l < r) { swap(s[l], s[r]); }
			++l; --r;
		}
		return s;
    }

	string reverseVowels_stack(string s) {
		stack<char> stk;
		for(char ch : s) {
			if (isVowel(ch)) { stk.push(ch); }
		}
		string res;
		for (char ch: s) {
			if (isVowel(ch)) {
				res += stk.top(); stk.pop();
			} else {
				res += ch;
			}
		}
		return res;
	}

	
private:
    bool isVowel(char x) {
        string t = "aeiouAEIOU";
        return t.find(x) != string::npos;
    }
};

void unit_test() {
	Solution s;
}

int main() {
	unit_test();
	return 0;
}
