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

// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

class Solution {
public:
	void helper(vector<pair<int, int>>& pairs, int left, int right, vector<int>& res) {
		if (left >= right) { return; }
		
		int mid = left + (right - left) / 2;
		helper(pairs, left, mid, res);
		helper(pairs, mid+1, right, res);

		int k = mid+1;
		for (int i = left; i <= mid; ++i) {
			while (k <= right && pairs[i].first > pairs[k].first) { ++k; }
			res[pairs[i].second] += k-mid-1;
		}
		inplace_merge(pairs.begin()+left, pairs.begin()+mid+1, pairs.begin()+right+1);
	}

    vector<int> countSmaller(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return {}; }
		vector<pair<int, int>> pairs;
		for (int i = 0; i < nsize; ++i) {
			pairs.push_back({nums[i], i});
		}
		vector<int> res(nsize, 0);

		helper(pairs, 0, nsize-1, res);
		return res;
    }	
};
