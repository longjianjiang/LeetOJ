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

// URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
// 题意不清。
// 1> 就遍历一遍，遇到空格替换成%20。
// 2> 不使用额外的空间，从后开始移动，最后截取。　
class Solution {
public:
    string replaceSpaces(string S, int length) {
		const string spaceStr = "%20";
		string res;
		int resSize = 0;
		for (auto ch : S) {
			if (ch == ' ') {
				if (resSize == length) { break; }
				++resSize;
				for (auto c : spaceStr) { res.push_back(c); }
			} else {
				++resSize;
				res.push_back(ch);
			}
		}
		
		int diff = length - resSize;
		for (int i = 0; i < diff; ++i) {
			for (auto c : spaceStr) { res.push_back(c); }
		}
		return res;
    }

	string replaceSpaces(string s, int length) {
		int pos = s.size()-1;

		for (int i = length-1; i >= 0; --i) {
			if (s[i] == ' ') {
				s[pos--] = '0';
				s[pos--] = '2';
				s[pos--] = '%';
			} else {
				s[pos--] = s[i];
			}
		}

		return s.substr(pos+1);
	}
};

int main() {
	string s1 = "   123  4 5  6   "; 
	int k1 = 9;

	string s2 = "    ";
	int k2 = 2;

	Solution s;
	string res1 = s.replaceSpaces(s1, k1);
	string res2 = s.replaceSpaces(s2, k2);

	cout << res1 << endl;
	cout << res2 << endl;

	return 0;
}
