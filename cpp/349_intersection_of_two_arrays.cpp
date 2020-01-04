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

// 给定两个数组，返回交集的元素，顺序不做要求
// 1> 使用set;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty()) { return {}; }

		unordered_set<int> set1;
		for (auto num: nums1) {
			set1.insert(num);
		}
		unordered_set<int> res;
		for (auto num: nums2) {
			if (set1.find(num) != set1.end()) {
				res.insert(num);
			}
		}
		return {res.begin(), res.end()};
    }

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		auto max = nums1.size() > nums2.size() ? nums1 : nums2;
		auto min = nums1.size() < nums2.size() ? nums1 : nums2;

		sort(max.begin(), max.end());
		sort(min.begin(), min.end());

		auto last = unique(min.begin(), min.end());

		vector<int> res;
		for (auto it = min.begin(); it < last; ++it) {
			int num = *it;
			if (binary_search(max.begin(), max.end(), num)) {
				res.push_back(num);
			}
		}
		return res;
	}
};
