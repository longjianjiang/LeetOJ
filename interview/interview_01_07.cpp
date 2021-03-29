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

/*
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int nsize = matrix.size();
		for (int i = 0; i <= nsize-2; ++i) {
			for (int j = 0; j < nsize - 2*i - 1; ++j) {
				int m = nsize-i-1;
				int n = j + i;

				int tmp = matrix[i][n]; // 15 -> 5 x固定, y变
				matrix[i][n] = matrix[m-j][i]; // 16 -> 15 x变, y固定
				matrix[m-j][i] = matrix[m][m-j]; // 11 -> 16 x固定, y变
				matrix[m][m-j] = matrix[n][m]; // 5 -> 11 x变, y固定
				matrix[n][m] = tmp;
			}
		}
    }
};
