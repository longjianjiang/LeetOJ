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

// 统计一个数字在排序数组中出现的次数。

// 1> 暴力，遍历一次统计次数；
// 2> 二分，因为有序，使用二分查找即可；
class Solution {
public:
	int helper(vector<int> data, int left, int right, int k) {
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (data[mid] == k) {
				return 1+helper(data, left, mid-1, k)+helper(data, mid+1, right, k);
			} else if (data[mid] > k) {
				return helper(data, left, mid-1, k);
			} else {
				return helper(data, mid+1, right, k);
			}
		}

		return 0;
	}

    int GetNumberOfK(vector<int> data ,int k) {
		int nsize = data.size();
		if (nsize == 0) { return 0; }

		return helper(data, 0, nsize-1, k);
    }
};
