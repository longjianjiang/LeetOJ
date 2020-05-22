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

class Solution {
public:
	bool isNumber(char ch) {
		return ch >= 48 && ch <= 57;
	}

	// 123
    int StrToInt(string str) {
		stack<int> s;
		
		int isPositive = 1;
		for (int i = 0; i < str.length(); ++i) {
			char ch = str[i];
			if (i == 0 && ch == '+') { continue; }
			if (i == 0 && ch == '-') { isPositive = -1; continue; }
			if (!isNumber(ch)) { return 0; }
			s.push(ch - '0');
		}

		int pos = 0;
		double res = 0;
		while (!s.empty()) {
			if (res > INT_MAX) { return isPositive > 0 ? INT_MAX : INT_MIN; }
			res += s.top() * pow(10, pos++);
			s.pop();
		}
		if (res > INT_MAX) { return isPositive > 0 ? INT_MAX : INT_MIN; }
		return (int)(res * isPositive);
    }
};

void unit_test() {
	Solution s;

	cout << s.StrToInt("123") << endl;
	cout << s.StrToInt("123x") << endl;
	cout << s.StrToInt("-2147483649") << endl;
	cout << INT_MIN << endl;
}

int main() {
	unit_test();
	return 0;
}
