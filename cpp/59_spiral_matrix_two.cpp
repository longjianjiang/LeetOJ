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

// 和54类型，按>v<^ 的方向进行遍历或者赋值即可；
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		if (n <= 0) { return {}; }
		if (n == 1) { return {{1}}; }

		vector<vector<int>> res(n, vector<int>(n, 0));
		int bx = 0, ex = n-1;
		int by = 0, ey = n-1;

		int num = 1;
		while (true) {
			// >
			for (int i = bx; i <= ex; ++i) {
				res[by][i] = num++;
			}
			if (++by > ey) { break; }
			// v
			for (int i = by; i <= ey; ++i) {
				res[i][ex] = num++;
			}
			if (--ex < bx) { break; }
			// <
			for (int i = ex; i >= bx; --i) {
				res[ey][i] = num++;
			}
			if (--ey < by) { break; }
			// ^
			for (int i = ey; i >= by; --i) {
				res[i][bx] = num++;
			}
			if (++bx > ex) { break; }
		}

		return res;
    }
};

void unit_test() {
	Solution s;
	auto res = s.generateMatrix(3);

	for (auto v : res) {
		for (auto num : v) {
			cout << num << " ";
		}
		cout << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
