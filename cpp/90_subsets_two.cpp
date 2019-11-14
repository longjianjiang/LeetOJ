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

// 返回数组的所有组合，数组中含有重复元素，所以需要一个过滤的操作。
class Solution {
public:
	void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int> chosen, int idx, int cnt) {
		if (cnt == chosen.size()) { res.push_back(chosen); return; }
		if (idx >= nums.size() || chosen.size() > cnt) { return; }

		for (int i = idx; i < nums.size(); ++i) {
			int num = nums[i];
			if (i > idx && nums[i] == nums[i-1]) { continue; }
			chosen.push_back(num);
			dfs(nums, res, chosen, i+1, cnt);
			chosen.pop_back();
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> chosen;

		sort(nums.begin(), nums.end());
		for (int cnt = 0; cnt <= nums.size(); ++cnt) {
			dfs(nums, res, chosen, 0, cnt);
		}

		return res;
    }
};


void unit_test() {
	Solution s;

	vector<int> nums = {1, 2, 2};
	auto res = s.subsetsWithDup(nums);

	for (auto sec : res) {
		cout << "[";
		for (auto num : sec) {
			cout << num << " ";
		}
		cout << "]";
	}
}

int main() {
	unit_test();
	return 0;
}
