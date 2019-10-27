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

// 给定一组不重复的数字，返回全排列。
// 1> 回溯
// 2> dac
class Solution {
public:
	void dfs(vector<int> nums, vector<int>& chosen, vector<vector<int>>& res) {
		if (nums.empty()) {
			res.push_back(chosen);
		} else {
			for (int i = 0; i < nums.size(); ++i) {
				int num = nums[i];
				chosen.push_back(num);
				nums.erase(nums.begin()+i);
				dfs(nums, chosen, res);
				chosen.pop_back();
				nums.insert(nums.begin()+i, num);
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
		vector<int> chosen;
		vector<vector<int>> res;

		dfs(nums, chosen, res);

		return res;
    }

	vector<vector<int>> permute_dac(vector<int>& nums) {
		if (nums.size() == 1) {
			return {nums};
		} else {
			vector<vector<int>> res;
			int n = nums.back(); nums.pop_back();
			vector<vector<int>> front = permute_dac(nums);

			for (auto vec: front) {
				for (int i = 0; i <= vec.size(); ++i) {
					auto tmp(vec);
					tmp.insert(tmp.begin()+i, n);
					res.push_back(tmp);
				}
			}

			return res;
		}
	}
};

void unit_test() {
	Solution s;

	vector<int> nums = {1, 2, 3};
	auto res = s.permute(nums);

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
