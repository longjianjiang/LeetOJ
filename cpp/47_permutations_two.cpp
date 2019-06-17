class Solution {
public:
	void dfs(vector<int> nums, vector<int>& chosen, vector<vector<int>>& res) {
		if (nums.empty()) {
			res.push_back(chosen);
			return;
		}

		unordered_set<int> us;
		for(int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			if (us.find(num) != us.end()) { continue; }

			us.insert(num);
			chosen.push_back(num);
			nums.erase(nums.begin()+i);
			dfs(nums, chosen, res);
			chosen.pop_back();
			nums.insert(nums.begin()+i, num);
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<int> chosen;
		vector<vector<int>> res;
		dfs(nums, chosen, res);
		return res;
    }
};
