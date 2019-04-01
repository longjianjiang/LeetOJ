#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int idx, int target, int right, vector<int>& nums, vector<int>& chosen, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(chosen); return; }
        if (target < 0 || idx >= nums.size()) { return; }

        for (int i = idx; i <= right; ++i) {
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(0, target, right, nums, chosen, res);
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
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> chosen;
        int right = getValidRightIndex(nums, target);

        dfs(0, target, right, nums, chosen, res);
        return (int)res.size();
    }
};