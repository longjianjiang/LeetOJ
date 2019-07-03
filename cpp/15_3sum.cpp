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

// 给定数组，找出3个一组和为0的所有情况，不能重复
// 将数组排序，从头开始遍历，当元素大于0则结束遍历；
// 以当前i开始，从两头left=i+1, right=size-1，三点求和，移动left，right，这样不会出现重复的情况
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.empty()) { return {}; }
		sort(nums.begin(), nums.end());

		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) { break; }
			int l = i+1, r = nums.size()-1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r]; 
				if (sum > 0) {
					r--;
				} else if (sum < 0) {
					l++;
				} else {
					res.push_back({nums[i], nums[l], nums[r]});
					while (l < r && nums[l] == nums[l+1]) {
						l++;
					}
					while (l < r && nums[r] == nums[r-1]) {
						r--;
					}
					l++;
					r--;
				}
			}
			while (i < nums.size()-1 && nums[i] == nums[i+1]) {
				i++;
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	auto res = s.threeSum(nums);
	
	for (auto vec: res) {
		cout << "[ ";
		for (auto n: vec) {
			cout << n << " ";
		}
		cout << "]\n";
	}
}

int main() {
	unit_test();
	return 0;
}
