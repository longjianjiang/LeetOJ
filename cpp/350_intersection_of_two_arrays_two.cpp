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

// 给定两个数组，返回交集元素，允许重复。
// 1> 使用map记录个数；
// 2> 先排序，使用双指针进行比较，相等放入数组中；
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty()) { return {}; }

		unordered_map<int, int> dict;
		for (auto num: nums1) {
			dict[num]++;
		}
		vector<int> res;
		for (auto num: nums2) {
			if (dict.find(num) != dict.end()) {
				if (dict[num] > 0) {
					res.push_back(num);
					dict[num]--;
				}
			}
		}
		return res;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty()) { return {}; }

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		int l1 = 0, l2 = 0;
		vector<int> res;
		while (l1 < nums1.size() && l2 < nums2.size()) {
			if (nums1[l1] < nums2[l2]) {
				++l1;
			} else if (nums1[l1] > nums2[l2]) {
				++l2;
			} else {
				res.push_back(nums1[l1]);
				++l1;
				++l2;
			}
		}

		return res;
	}
}
