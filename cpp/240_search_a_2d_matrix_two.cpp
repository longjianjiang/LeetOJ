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

// 给定一个矩阵，从左往右有序，从上到下有序，判断target 是否存在
class Solution {
public:
	// bs, O(mlogN)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = (int)matrix.size();
		if (row == 0) { return false; }
		int col = matrix[0].size();
		if (col == 0) { return false; }

		int left = 0, right = col-1;
		int cur_row = 0;
		while (cur_row < row) {
			while (left <= right) {
				int mid = left + (right - left) / 2;
				int num = matrix[cur_row][mid];
				if (num == target) {
					return true;
				} else if (num > target) {
					right = mid-1;
				} else {
					left = mid + 1;
				}
			}
			++cur_row;
			left = 0, right = col-1;
		}
		return false;
    }

	// O(m+n)
	bool searchMatrix_from_corner(vector<vector<int>>& matrix, int target) {
		int row = (int)matrix.size();
		if (row == 0) { return false; }
		int col = matrix[0].size();
		if (col == 0) { return false; }
	
		int x = 0, y = col-1;
		while (x <= row-1 && y >= 0) {
			int num = matrix[x][y];
			if (num == target) {
				return true;
			} else {
				num > target ? --y : ++x;	
			}
		}

		return false;
	}
};


