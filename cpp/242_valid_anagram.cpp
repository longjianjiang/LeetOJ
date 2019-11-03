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

// 判断两个字符串是否是由相同字符组成的;
// 用map即可；

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }

		unordered_map<char, int> um;
		for (char ch : s) {
			um[ch] += 1;
		}
		for (char ch : t) {
            um[ch] -= 1;
		}
        for (char ch : s) {
            if (um[ch] != 0) { return false; }
		}
		return true;
    }
};
