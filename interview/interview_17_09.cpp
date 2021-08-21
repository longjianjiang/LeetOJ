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

// 规则是3，5，7这三个数中中依次乘以倍数组成的一个升序序列，给定k，返回这个数字。开始数字是1。
// [1, 3, 5, 7, 9, 15, 21]
// 3a + 5b + 7c
class Solution {
public:
    int getKthMagicNumber(int k) {
		vector<int> arr(k, 1);

		int p3 = 0, p5 = 0, p7 = 0;
		for (int i = 1; i < k; ++i) {
			int tmp = min(arr[p3] * 3, min(arr[p5] * 5, arr[p7] * 7));
			arr[i] = tmp;
			if (arr[p3] * 3 == tmp) { ++p3; }
			if (arr[p5] * 5 == tmp) { ++p5; }
			if (arr[p7] * 7 == tmp) { ++p7; }
		}

		return arr[k-1];
    }
};
