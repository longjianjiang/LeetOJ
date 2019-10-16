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

// 规定[0, 1, 8] 旋转后还是自己，[2, 5],[6, 9]旋转后变成对方，其他数字旋转后非法
// 给定N，给出1-N中有多少旋转后还是有效的，同时发生了变化。
class Solution {
public:

	bool valid(int n) {
		string str = to_string(n);
		bool flag = false;

		for (char ch : str) {
			if (ch == '3' || ch == '4' || ch == '7') return false;
			if (ch == '2' || ch == '5' || ch == '6' || ch == '9') { flag = true; }
		}

		return flag;
	}

    int rotatedDigits(int N) {
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			if (valid(i)) { ++res; }
		}
		return res;
    }
};
