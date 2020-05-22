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

// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

// 1> 拆分成进位和和两部分；
class Solution {
public:
    int Add(int num1, int num2) {
		while (num2) {
			int carry = (num1 & num2) << 1;
			int sum = num1 ^ num2;
			num1 = sum;
			num2 = carry;
		}

		return num1;
	}
};
