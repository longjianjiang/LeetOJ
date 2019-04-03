#include <iostream>
#include <vector>

using namespace std;

// 给定n和k，求1-n的k个数字的组合列表
// 使用回溯发即可

class Solution {
private:
    void dfs(int idx, int count, vector<int>& nums, vector<int>& chosen, vector<vector<int>>& res) {
        if (chosen.size() == count) { res.push_back(chosen); return; }
        if (chosen.size() > count || idx >= nums.size()) { return; }

        for (int i = idx; i < nums.size(); ++i) {
            int n = nums[i];
            chosen.push_back(n);
            dfs(i+1, count, nums, chosen, res);
            chosen.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        vector<int> chosen;
        vector<vector<int>> res;
        dfs(0, k, nums, chosen, res);

        return res;
    }
};