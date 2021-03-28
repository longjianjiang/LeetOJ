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
 字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

输入:
first = "pale"
second = "ple"
输出: True

输入:
first = "pales"
second = "pal"
输出: False
 */

// 双指针遍历两个字符串，当第一次遇到不相等，此时进行三种不同的编辑操作，生成四个字符串，然后去判断是否其中一对相等即可。
class Solution {
public:
    bool oneEditAway(string first, string second) {
		if (first == second) { return true; }
		int nsize1 = first.size(), nsize2 = second.size();
		int i = 0, j = 0;

		string left_first;
		vector<string> left_seond;
		while (i < nsize1 && j < nsize2) {
			if (first[i] == second[j]) {
				++i;
				++j;
				continue;
			}
			break;
		}

		for (int k = i; k < nsize1; ++k) {
			left_first.push_back(first[k]);
		}

		for (int m = 0; m < 3; ++m) {
			string s;
            if (m == 0) { } // delete
			if (m == 1) { s.push_back(first[i]); } // replace
			if (m == 2) { s.push_back(first[i]); s.push_back(second[j]); } // add
			for (int k = j+1; k < nsize2; ++k) {
				s.push_back(second[k]);
			}
			left_seond.push_back(s);
		}
		for (auto str : left_seond) {
			if (str == left_first) { return true; }
		}

		return false;
    }
};

void unit_test() {
	Solution s;

	auto res1 = s.oneEditAway("pale", "ple");
	auto res2 = s.oneEditAway("pales", "pal");

	cout << res1 << endl;
	cout << res2 << endl;
}

int main() {
	unit_test();
	return 0;
}
