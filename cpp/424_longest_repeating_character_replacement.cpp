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

// 给定字符串和k，要求返回替换k次后，s子串中所有字符一样的子串的最大长度，"abab", 2 => 4
// 使用所谓的滑动窗口，从头开始遍历，依次比较每个字符，替换k次后，计算子串长度；然后更新left继续遍历；
// 遍历结束后，如果k大于0，则尝试反向遍历最后一组子串。
class Solution {
public:
    int characterReplacement(string s, int k) {
		if (s.size() <= 1) { return s.size(); }
		
        int res = 1, max_len = 1, times = k;
		char ch = s[0];
        int left = 0, right = 1;

        while (right < s.size()) {
			if (s[right] == ch) {
				res += 1;
			} else {
				if (k == 0) {
					if (res > max_len) { max_len = res; }
					while(left <= right) {
						if (s[left] != ch) {
							ch = s[left];
							res = 1;
							right = left + 1;
							k = times;
							break;
						}
						left += 1;
					}
					continue;
				} else {
					k -= 1;
					res += 1;
				} 
			}
			right += 1;
        }

		if (k > 0) { // case "ABBB", 2
			while (k > 0 && left > 0) {
				if (ch != s[--left]) {
					k -= 1;
				}
				res += 1;
			}
		}

        return max_len > res ? max_len : res;
    }
};

void unit_test() {
	Solution s;

	assert(s.characterReplacement("ABAB", 2) == 4);
	assert(s.characterReplacement("AABABBA", 1) == 4);
	assert(s.characterReplacement("BAAA", 0) == 3);
	assert(s.characterReplacement("AAAB", 0) == 3);
	assert(s.characterReplacement("ABBB", 2) == 4);
}

int main() {
	unit_test();
	return 0;
}
