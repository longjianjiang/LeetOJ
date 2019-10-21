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

// 通配符匹配，?匹配任意一个字符，*匹配任意长度任意字符包含空。

/*
s = "adceb"
p = "*a*b"

s = "acdcb"
p = "a*c?b"
*/

class Solution {
public:
    bool isMatch(string s, string p) {
		if (p == "*" || s == p) { return true; }
		
		int i = 0, j = 0;
		int is = -1, js = -1;
		while (i < s.size()) {
			if (s[i] == p[j] || p[j] == '?') {
				++i; ++j;
			} else if (p[j] == '*') {
				is = i; js = j++;
			} else if (is >= 0) {
				i = ++is; j = js+1;
			} else {
				return false;
			}
		}

		while (j < p.size() && p[j] == '*') { ++j; }
		return j == p.size();
    }
};
