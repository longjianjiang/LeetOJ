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

// 给定n*n的矩阵，顺时针旋转90度，原地调整。
// 观察到如下规律，以4*4为例：
/*
 * 	1  2  3  4
 * 	5  6  7  8
 * 	9  10 11 12
 * 	13 14 15 16
 */
// 要想完成旋转，从外矩形开始，首先调整矩形最外侧的四条边上的数字:
// 1为first，4为second，16为third，13为fourth； first放fourth，second放first，third放second，fourth放first。
// 接下来往前移动一位，按上面的顺序交换[2, 8, 15, 9]. 最外层的边需要交换nsize-1次。
// 接下来到了内层的边，是一个2*2的矩形，依然按照之前的交换规律，此时需要交换nsize-2-1也就是1次即可。
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rc = matrix.size();

        for (int i = 0; i <= rc-2; ++i) {
            for (int j = 0; j < rc-2*i-1; ++j) {
                int x = i+j;
                int y = rc-1-i;

                int first = matrix[i][x];
                int second = matrix[x][y];
                int third = matrix[y][y-j];
                int fourth = matrix[y-j][i];

                matrix[i][x] = fourth;
                matrix[x][y] = first;
                matrix[y][y-j] = second;
                matrix[y-j][i] = third;
            }
        }
    }
};

void unit_test() {
	Solution s;

	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	s.rotate(matrix);

	for (auto list: matrix) {
		for (auto num: list) {
			cout << num << " ";
		}
		cout << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
