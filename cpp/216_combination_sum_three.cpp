#include <iostream>
#include <vector>

using namespace std;

// 类似29题，nums其实就是1-9，同时对组合的个数有要求

class Solution {
private:
    void dfs(int idx, int target, int right, int count, vector<int>& nums, vector<int>& chosen, vector<vector<int>>& res) {
        if (0 == target && chosen.size() == count) { res.push_back(chosen); return; }
        if (target < 0 || idx >= nums.size() || chosen.size() > count) { return; }

        for (int i = idx; i <= right; ++i) {
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(i+1, target, right, count, nums, chosen, res);
            target += n;
            chosen.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> chosen;
        vector<vector<int>> res;
        int right = (int)nums.size()-1;
        dfs(0, n, right, k, nums, chosen, res);

        return res;
    }
};