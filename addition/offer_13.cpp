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

/**
  * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
  */

// 1> 第一次遍历，找到奇数和偶数；第二次遍历，进行覆盖；
class Solution {
public:
    void reOrderArray(vector<int> &array) {
		vector<int> evenArr;
		vector<int> oddArr;

		for (int i = 0; i < array.size(); ++i) {
			int num = array[i];
			if (num & 1 == 1) {
				oddArr.push_back(num);
			} else {
				evenArr.push_back(num);
			}
		}
		for (int i = 0; i < oddArr.size(); ++i) {
			array[i] = oddArr[i];
		}
		int prefixIdx = oddArr.size();
		for (int i = 0; i < evenArr.size(); ++i) {
			array[prefixIdx+i] = evenArr[i];
		}
    }
};
