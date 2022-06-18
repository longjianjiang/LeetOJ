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

// 给你一个字符串 s，找到 s 中最长的回文子串。
// s = "babad"
// 1> 遍历，根据回文的特点进行两端进行移动，定位到子串;
class Solution {
public:
    string longestPalindrome(string s) {
		int nsize = s.size();
        if (nsize <= 1) { return s; }

        unordered_set<char> us;
        string res = s.substr(0, 1);

        for (int i = 0; i < nsize; ++i) {
            int l = i, r = i+1;
            us.clear();
            us.insert(s[l]);
            while (r < nsize && us.find(s[r]) == us.end()) {
                us.insert(s[r]);
                ++r;
            }
            // babad
            if (s[r] == s[r-1]) {
                l = r-1;
                // case "sooos"
                while (r + 1 < nsize && s[r+1] == s[r]) { ++r; }
                while (l-1 >= 0 && r+1 < nsize && s[l-1] == s[r+1]) {
                    --l; ++r;
                }
                string tmp = s.substr(l, r-l+1);
                if (tmp.size() > res.size()) {
                    res = tmp;
                }
            }
            else if (r-2 >= 0 && s[r] == s[r-2]) {
                l = r-2;
                while (l-1 >= 0 && r+1 < nsize && s[l-1] == s[r+1]) {
                    --l; ++r;
                }
                string tmp = s.substr(l, r-l+1);
                if (tmp.size() > res.size()) {
                    res = tmp;
                }
            } else {

            }
        }
        return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.longestPalindrome("a") << endl;
	cout << s.longestPalindrome("aa") << endl;
	cout << s.longestPalindrome("aaa") << endl;
	cout << s.longestPalindrome("aca") << endl;
	cout << s.longestPalindrome("aabba") << endl;
	cout << s.longestPalindrome("abcba") << endl;
	cout << s.longestPalindrome("abba") << endl;
	cout << s.longestPalindrome("babad") << endl;
}

int main() {
	unit_test();
	return 0;
}
