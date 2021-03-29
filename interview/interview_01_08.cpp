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

// 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
// 遍历矩阵，将0的x和y记录下来，然后将这些x,y行和列清零。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row == 0) { return; }
		int col = matrix[0].size();
		if (col == 0) { return; }

		unordered_set<int> xSet;
		unordered_set<int> ySet;

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrix[i][j] == 0) {
					xSet.insert(i); 
					ySet.insert(j);
				}
			}
		}

		for (auto x : xSet) {
			for (int y = 0; y < col; ++y) { matrix[x][y] = 0; }
		}
		for (auto y : ySet) {
			for (int x = 0; x < row; ++x) { matrix[x][y] = 0; }
		}
    }
};
