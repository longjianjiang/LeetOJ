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

// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
// 本题，牛客网测试用力有问题，leetcode可以测试通过；

// 1> 第一步统计字符串中所有数字的出现的idx；第二次遍历存储idx数组的数组，找到个数为1的下标，返回最小的或者返回对应的字符；
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		int nsize = str.size();
		if (nsize == 0) { return -1; }
		vector<vector<int>> list(52); 

		for (int i = 0; i < nsize; ++i) {
			char ch = str[i];
			int idx = ch - 'a';

			list[idx].push_back(i);
		}
		int resIdx = INT_MAX;
		char resCh = ' ';
		for (int i = 0; i < list.size(); ++i) {
			vector<int> v = list[i];
			if (v.size() == 1 && v.back() < resIdx) { 
				resIdx = v.back(); 
				resCh = i + 'a';
			}
		}
		return (resIdx == INT_MAX) ? ' ' : resCh;
		return (resIdx == INT_MAX) ? -1 : resIdx;
    }
};

void unit_test() {
	Solution s;

	cout << s.FirstNotRepeatingChar("abcab") << endl;
}

int main() {
	unit_test();

	char res = 2 + 'a';
	cout << res << endl;
	return 0;
}
