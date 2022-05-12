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
给你一个字符串 s ，颠倒字符串中 单词 的顺序。
输入：s = "the sky is blue"
输出："blue is sky the"
*/

class Solution {
public:
    string reverseWords(string s) {
		int nsize = s.size();
		if (nsize == 0) { return ""; }

		int r = 0;
		while (r < nsize && s[r] == ' ') { ++r; }

		int l = r;
		vector<string> arr;
		while (r < nsize) {
			//输入：s = "the  sky is blue  "
			if (s[r] == ' ') {
				if (s[l] != ' ') {
					auto substr = s.substr(l, r-l);
					arr.push_back(substr);
				}
				l = r + 1;
			}
			++r;
		}
		if (l < nsize && s[l] != ' ') {
			arr.push_back(s.substr(l, r-l));
		}

		string res = "";
		// for auto can be bad malloc
		for (int i = arr.size()-1; i >= 0; --i) {
			res += arr[i];
			if (i > 0) { res += " "; }
		}
		return res;
    }

	string reverseWordsInPlace(string s) {
		auto reverseFunc = [](string& s, int l, int r) {
			while (l < r) {
				swap(s[l], s[r]);
				++l; --r;
			}
		};

		int nsize = s.size();
		if (nsize == 0) { return ""; }

		// 1> reverse all string;
		reverseFunc(s, 0, nsize-1);

		// 2> remove left space;
		int l = 0, r = 0;
		while (!s.empty() && s[r] == ' ') { s.erase(s.begin() + r); }

		// 3> reverse each word;
		while (r < s.size()) {
			// "eulb  si yks  eht  "
			if (s[r] == ' ') {
				reverseFunc(s, l, r-1);
				++r;
				while (r < s.size() && s[r] == ' ') { s.erase(s.begin() + r); }
				l = r;
			}
			++r;
		}
		// 4> check last word;
		if (l < s.size() && s[l] != ' ') { reverseFunc(s, l, r-1); }
		// 5> remove end space;
		if (*(s.end()-1) == ' ') { s.erase(s.end()-1); }

		return s;
	}
};

void unit_test() {
	Solution s;
	string str = "the sky is blue";
	cout << s.reverseWordsInPlace(str) << endl;
}

int main() {
	unit_test();
	return 0;
}
