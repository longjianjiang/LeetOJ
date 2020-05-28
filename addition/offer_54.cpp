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

// 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
// 如果当前字符流没有存在出现一次的字符，返回#字符。

// 使用map，key为字符，value为idx；插入的存储出idx，取的时候，取idx最小的，也就是最先出现一次的；
class Solution
{
public:
	vector<int> dict;
	int idx;

	Solution(): idx(1), dict(vector<int>(256, 0)) {}

    //Insert one char from stringstream
    void Insert(char ch) {
		if (dict[ch] == 0) {
			dict[ch] = idx;
		} else if (dict[ch] > 0) {
			dict[ch] = -1;
		}

		++idx;
	}

   	//return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
		char ch = '#';
		int minIdx = INT_MAX;
		for (int i = 0; i < 256; ++i) {
			if (dict[i] > 0 && dict[i] < minIdx) {
				ch = (char)(i);
				minIdx = dict[i];
			}
		}

		return ch;
	}

};
