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

// 给定不重复的数字，返回所有可能的排列情况；
/*
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */
class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int> chosen, int cnt, vector<int>& nums) {
		if (chosen.size() == cnt) {
			res.push_back(chosen);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			chosen.push_back(num);
			nums.erase(nums.begin()+i);
			dfs(res, chosen, cnt, nums);
			chosen.pop_back();
			nums.insert(nums.begin()+i, num);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> chosen;
		dfs(res, chosen, nums.size(), nums);

		return res;
    }
};
// 1 2 3
// chosen [1, 2], nums [3]
// chosen [1], nums [2, 3]
// i = 1,
// chosen[1, 3], nums [2]
// i = 0
// chosen[1, 3, 2], nums[]
// chosen[1, 3], nums[2]
// i = 1
// chosen[1], nums[2, 3]
// i = 0
// chosen=[], nums[1, 2, 3]
// 给定可能重复的数字，返回排列；
class Solution2 {
public:
	void dfs(vector<vector<int>>& res, vector<int> chosen, int cnt, vector<int>& nums) {
		if (chosen.size() == cnt) {
			res.push_back(chosen);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			// 过滤掉相同的
			if (i > 0 && nums[i] == nums[i-1]) { continue; }
			int num = nums[i];
			chosen.push_back(num);
			nums.erase(nums.begin()+i);
			dfs(res, chosen, cnt, nums);
			chosen.pop_back();
			nums.insert(nums.begin()+i, num);
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> res;
		vector<int> chosen;
		dfs(res, chosen, nums.size(), nums);

		return res;
	}
}
