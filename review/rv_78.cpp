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

class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int> chosen, vector<int> nums, int count, int idx) {
        if (chosen.size() == count) {
            res.push_back(chosen);
            return;
        }
        int nsize = nums.size();
        if (idx >= nsize || chosen.size() > count) { return; }
        for (int i = idx; i < nsize; ++i) {
            int num = nums[i];
            chosen.push_back(num);
            dfs(res, chosen, nums, count, i+1);
            chosen.pop_back();
        }
	}

    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		vector<int> chosen;
		for (int i = 1; i <= nums.size(); ++i) {
			dfs(res, chosen, nums, i, 0);
		}

		return res;
    }
};
