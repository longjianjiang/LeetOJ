#include <iostream>
#include <vector>

using namespace std;

// 类似29题，此题不要求返回所有组合，仅仅返回组合的个数即可
// 同时要求组合允许从头部开始继续寻找，所以搜索中每次从头开始搜索，这样会很耗时，提交后会超时。
// 所以只能换种思路，使用动态规划来做

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
        // time limit exceeded
        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> chosen;
        int right = getValidRightIndex(nums, target);

        dfs(0, target, right, nums, chosen, res);
        return (int)res.size();
        */

       // dp
       vector<int> dp(target + 1);
       dp[0] = 1;
       sort(nums.begin(), nums.end());
       for (int i = 1; i <= target; ++i) {
           for (auto num: nums) {
               if (i < num) { break; }
               dp[i] += dp[i - num];
           }
       }
       return dp.back();
    }
};