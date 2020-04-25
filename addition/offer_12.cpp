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

/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 保证base和exponent不同时为0 
 *
 */

// 1> 判断exponent的正负；
// 2> 处理倒置的时候，分母为0的情况；
// 3> 计算次方，使用递归，a^n = a^(n/2) * a^(n/2); a^n = a^(n-1/2) * a^(n-1/2) * n;
class Solution {
public:
    double Power(double base, int exponent) {
		int n = exponent;
		if (exponent == 0) {
			return 1;
		} else if (exponent < 0) {
			if (base == 0) {
				throw new RuntimeException("The denominator cannot be 0");
			}
			n = -exponent;
		}
		double res = powerWithUnsignedExponent(base, n);
		return exponent < 0 ? 1/res : res;
    }

	double powerWithUnsignedExponent(double base, int n) {
		if (n == 0) { return 1; }
		if (n == 1) { return base; }
		double res = powerWithUnsignedExponent(base, n >> 1);
		res *= res;
		if (n & 1 == 1) {
			res *= base;
		}
		return res;
	}
};
