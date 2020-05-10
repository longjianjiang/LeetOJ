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


// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

// 1> 暴力，两层循环，统计个数；
// 2> 归并的思想；计算两边的个数，然后比较有序的两边的个数，返回三者和；
// 本题牛客网上的用例无法通过，leetcode可以；

// 7564
class Solution {
public:
	int helper(vector<int>& data, vector<int>& copy, int left, int right) {
		if (left >= right) { return 0; }
		int mid = left + (right - left) / 2;
		int leftCnt = helper(data, copy, left, mid);
		int rightCnt = helper(data, copy, mid+1, right);

		int i = mid, j = right;
		int idx = right;
		int cnt = 0;
		while (i >= left && j >= mid+1) {
			if (data[i] > data[j]) {
				copy[idx--] = data[i--];
				cnt += (j-mid);
			} else {
				copy[idx--] = data[j--];
			}
		}
		while (i >= left) { copy[idx--] = data[i--]; }
		while (j >= mid+1) { copy[idx--] = data[j--]; }

		for (int i = left; i <= right; ++i) {
			data[i] = copy[i];
		}

		return leftCnt + rightCnt + cnt;
	}

    int InversePairs(vector<int> data) {
		int nsize = data.size();
		if (nsize == 0) { return 0; }

		vector<int> copy(nsize, 0);
		return helper(data, copy, 0, nsize-1);
    }

	int inversePairs(vector<int> nums) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }

		// 1 2 5
		vector<int> v; v.push_back(nums[nsize-1]);
		int res = 0;
		for (int i = nsize-2; i >= 0; --i) {
			int num = nums[i];
			int idx = -1;
			for (int j = 0; j < v.size(); ++j) {
				if (v[j] >= num) {
					idx = j;
					v.insert(v.begin()+idx, num);
					res += j;
				}
			}
			if (idx == -1) {
				res += v.size();
				v.push_back(num);
			}
		}
		return res;
	}
};
