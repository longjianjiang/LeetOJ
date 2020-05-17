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

// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

// 1> 遍历即可，注意空格的判定；
class Solution {
public:
    string reverseWords(string s) {
		if (s.empty()) { return s; }

		vector<string> list;
		bool firstSpace = true;
		int left = -1;
		for (int i = 0; i < s.length(); ++i) {
			if (firstSpace && s[i] == ' ') { continue; }
			if (firstSpace) { 
				firstSpace = false; 
				left = i;
			}
			if (s[i] == ' ') {
				string str = s.substr(left, i-left);
				list.push_back(str);
				firstSpace = true;
				left = -1;
			}
		}
		if (left >= 0) {
			string str = s.substr(left, s.length()-left);
			list.push_back(str);
		}
		reverse(list.begin(), list.end());
		string res;
		int nsize = list.size();
		for (int i = 0; i < nsize; ++i) {
			string str = list[i];
			res += str;
			if (i < nsize-1) { res += " "; }
		}

		return res;
    }
};

void unit_test() {
	Solution s;
	
	cout << s.reverseWords("the sky is blue") << endl;
	cout << s.reverseWords("  hello world!  ") << endl;
	cout << s.reverseWords("a good   example") << endl;
}

int main() {
	unit_test();
	return 0;
}
