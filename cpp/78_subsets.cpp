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

// 给定distinct数组，返回所有组合，也就是从数组中选择0-size个数字。
// 回溯即可；

class Solution {
public:
	void dfs(vector<int>& nums, vector<int>& chosen, vector<vector<int>>& res, int cnt, int idx) {
		if (cnt == chosen.size()) { res.push_back(chosen); return; }
		if (chosen.size() > cnt || idx >= nums.size()) { return; }

		for (int i = idx; i < nums.size(); ++i) {
			int n = nums[i];
			chosen.push_back(n);
			dfs(nums, chosen, res, cnt, i+1);
			chosen.pop_back();
		}
	}

    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> chosen;

		for (int cnt = 0; cnt <= nums.size(); ++cnt) {
			dfs(nums, chosen, res, cnt, 0);
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> arr = {1, 2, 3};
	auto res = s.subsets(arr);

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
