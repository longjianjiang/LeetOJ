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

// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

// 1> 直接两次substr；
// 2> 按要求改变数组中的元素；
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int nsize = str.length();
		if (n >= nsize) { return str; }
		// auto left = str.substr(0, n);
		// auto right = str.substr(n, nsize-n);
		// return right+left;

        vector<char> left;
		for (int i = 0; i < n; ++i) {
			left.push_back(str[i]);
		}
		for (int i = 0; i < nsize-n; ++i) {
			str[i] = str[n+i];
		}
        int idx = 0;
		for (int i = nsize-n; i < nsize; ++i) {
			str[i] = left[idx++];
		}

		return str;
    }
};
