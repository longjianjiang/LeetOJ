#include <iostream>
#include <vector>

using namespace std;

// 类似39题，只是此题要求不允许重复使用数组中的元素

class Solution {
private:
    void dfs(int idx, int target, int right, vector<int>& nums, vector<int>& chosen, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(chosen); return; }
        if (target < 0 || idx >= nums.size()) { return; }

        for (int i = idx; i <= right; ++i) {
            if (i > idx && nums[i] == nums[i-1]) { continue; }
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(i+1, target, right, nums, chosen, res);
            target += n;
            chosen.pop_back();
        }
    }

    int getValidRightIndex(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target) {
                return i - 1;
            } else if (nums[i] == target) {
                return i;
            }
        }
        return (int)(nums.size()-1);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> chosen;
        int right = getValidRightIndex(candidates, target);

        dfs(0, target, right, candidates, chosen, res);
        return res;
    }
};