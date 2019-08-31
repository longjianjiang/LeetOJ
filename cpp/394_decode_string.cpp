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
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

// 建2个栈，一个栈s1存字符，当遇到 2[xx] 这种的形式，将其对应的字符串加入另一个栈s2，同时s1存一个标记字符。
class Solution {
public:
	string get_times_str(string item, int times) {
		if (times <= 1) { return item; }
		string res = item;
		while (times > 1) {
			res += item;
			--times;
		}
		return res;
	}

	bool is_letter(char c) {
		if (c >= 'a' && c <= 'z') { return true; }
		if (c >= 'A' && c <= 'Z') { return true; }
		return false;
	}

    string decodeString(string s) {
		if (s.empty()) { return s; }

		int nsize = (int)s.size();
		string res;
		stack<char> stk;
		stack<string> rs_stk;

		for (int i = 0; i < nsize; ++i) {
			char ch = s[i];
			if (stk.empty() && is_letter(ch)) { res += ch; continue;  }
			if (ch != ']') {
				stk.push(ch);
			} else {
				string substr;
				while (stk.top() != '[') {
					char c = stk.top(); stk.pop();
					if (c == '$') {
						substr += rs_stk.top(); rs_stk.pop();
					} else {
						substr += c;
					}
				}
				stk.pop(); // remove '['
				int cnt = 0, bit = 0;
				while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
					int num = stk.top()-'0';
					cnt += num * pow(10, bit++);
					stk.pop();
				}
				substr = get_times_str(substr, cnt);

				if (stk.empty()) {
					reverse(substr.begin(), substr.end());
					res += substr;
					continue;
				}
				rs_stk.push(substr);
				stk.push('$');
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.decodeString("3[a2[c]]") << endl;
	cout << s.decodeString("2[abc]3[cd]ef") << endl;
	cout << s.decodeString("3[a]2[bc]") << endl;
	cout << s.decodeString("17[leetcode]") << endl;
	cout << s.decodeString("3[a]2[b4[F]c]") << endl;
}

int main() {
	unit_test();
	return 0;
}


