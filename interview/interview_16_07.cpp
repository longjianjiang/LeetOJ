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

// 编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。

class Solution {
public:
    int maximum(int a, int b) {
		// 提前转long，否则结果用int存溢出了。
    	long diff = (long)a - (long)b;
		//long diff = a - b;
		auto index = to_string(diff)[0];

		unordered_map<char, int> dict;
		dict['-'] = b;
		for (int i = 0; i <= 9; ++i) { dict[i + '0'] = a; }

		return dict[index];
    }
};

void unit_test() {
	Solution s;

	cout << s.maximum(INT_MAX, INT_MIN) << endl;
}

int main() {
	unit_test();
	return 0;
}
