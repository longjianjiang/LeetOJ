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

// n皇后问题，给定n返回解的个数。
// 这里使用一维数组，pos[i] 表示第i行的Q放在了哪一列上，可以节省空间。

/*
+----+----+----+----+
|    | L1 |    | R1 |
+----+----+----+----+
|    |    | Q  |    |
+----+----+----+----+
|    | L2 |    | R2 |
+----+----+----+----+
|    |    |    |    |
+----+----+----+----+
*/


class Solution {
public:
	bool is_valid(vector<int>& pos, int row, int col) {
		for (int i = 0; i < row; ++i) {
			bool one = (pos[i]==col); // 同一列是否存在Q
			bool two = ( (row-i) == abs(col - pos[i]) ); // 对角线([-,-], [-,+])是否相邻
			if (one || two) { return false; }
		}
		return true;
	}

	void dfs(vector<int>& pos, int row, int& res) {
		int n = (int)pos.size();
		if (row == n) { ++res; return; }

		for (int i = 0; i < n; ++i) {
			if (is_valid(pos, row, i)) {
				pos[row] = i;
				dfs(pos, row+1, res);
				pos[row] = -1;
			}
		}
	}

    int totalNQueens(int n) {
		int res = 0;
		vector<int> pos(n, -1);
		
		dfs(pos, 0, res);
		return res;
    }
};
