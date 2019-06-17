class Solution {
public:
	void dfs(vector<int> nums, vector<int>& chosen, vector<vector<int>>& res) {
	}

    vector<vector<int>> permute(vector<int>& nums) {
		vector<int> chosen;
		vector<vector<int>> res;

		dfs(nums, chosen, res);

		return res;
    }
};
