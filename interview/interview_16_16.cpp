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
 给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。
 注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

 输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
 输出： [3,9]
*/
// 两次遍历，寻找两边的逆序对，确定区间。因为如果是有序，数组元素的位置是不需要移动的。
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
		int nsize = array.size();
		vector<int> res = {-1, -1};
		if (nsize <= 1) { return res; }

		int maxValue = INT_MIN, minValue = INT_MAX;
		for (int i = 0; i < nsize; ++i) {
			if (array[i] < maxValue) {
				res[1] = i;
			} else {
				maxValue = max(maxValue, array[i]);
			}
		}
		for (int i = nsize-1; i >= 0; --i) {
			if (array[i] > minValue) {
				res[0] = i;
			} else {
				minValue = min(minValue, array[i]);
			}
		}

		return res;
    }
};
