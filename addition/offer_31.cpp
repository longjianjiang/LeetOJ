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

// 给定n，返回1-n所有数字中1的个数；

// 1> 暴力，统计每个数字中1的个数；
class Solution {
public:
	int numberOf1(int n) {
		int res = 0;
		while (n) {
			if (n % 10 == 1) { ++res; }
			n /= 10;
		}
		return res;
	}
    int NumberOf1Between1AndN_Solution(int n) {
		if (n < 1) { return 0; }

		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += numberOf1(i);
		}
		return res;
	}
};
