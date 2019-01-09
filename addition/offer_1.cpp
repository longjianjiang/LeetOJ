#include <iostream>
#include <vector>

using namespace std;

// 给定一个二维数组，数组从左往右，从下往上，都是依次递增，要求判断一个数字是否存在在数组中。

// 暴力的就不说了，开始想着以对角线上的数为界，首先比较对角线上的数，
// 如果大于target，则取当前列上的其他数字进行二分查找，否则取当前行上的其他数字进行二分查找，
// 更新行和列，直到右上方的数字，遍历结束

bool FindVersonOne(int target, vector<vector<int> > array) {
    int len = (int)array[0].size()-1;
    int row = (int)array.size()-1;
    int col = 0;
    while (row >= 0 && col <= len) {
        int middle = array[row][col];
        if (middle == target) {
            return true;
        } else if (middle > target) {
            int left = 0, right = (int)row-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (array[col][mid] == target) {
                    return true;
                } else if (array[col][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        } else {
            int left = col+1, right = len;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (array[row][mid] == target) {
                    return true;
                } else if (array[row][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        row -= 1; col += 1;
    }
    return false;
}

// 后来发现上面这种方法没有利用好数组的结构，其实还有更加简单的方法，
// 依然从数组左下角的数开始，如果大于target，则所在行 -1；否则所在列 +1，直到找到，否则返回false，
// 利用这种方法则更加高效，代码也更简洁，所以这题发现规律后就显得很简单了。

bool FindVersonTwo(int target, vector<vector<int> > array) {
    int rows = (int)array.size(), cols = (int)array[0].size();
    int i = rows-1, j = 0;
    while (i >= 0 && j < cols) {
        if (array[i][j] == target) {
            return true;
        } else if (array[i][j] < target) {
            j++;
        } else {
            i--;
        }
    }
    return false;
}