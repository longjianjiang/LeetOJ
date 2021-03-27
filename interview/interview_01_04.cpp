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
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）
*/

// 使用map记录每个字符出现的次数，当次数为奇数的字符小于等于1则可以构成回文。
class Solution {
public:
    bool canPermutePalindrome(string s) {
		unordered_map<char, int> dict;
		for (auto ch : s) {
			dict[ch] += 1;
		}

		int cnt = 0;
		for (auto item : dict) {
			if (item.second % 2 == 1) { ++cnt; }
			if (cnt > 1) { return false; }
		}

		return true;
    }
};
