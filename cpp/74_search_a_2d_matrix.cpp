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

// 给定矩阵，第n行首元素大于上一行最后一个元素，每行元素升序
// 当做一个一维数组来做，使用二分
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = (int)matrix.size();
		if (row == 0) { return false; }
		int col = matrix[0].size();
		if (col == 0) { return false; }

        int left = 0, right = row*col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = matrix[mid/col][mid%col];
            if (num == target) {
                return true;
            } else if (num > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return false;
    }
};
