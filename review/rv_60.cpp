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
	// "123"
	void dfs(vector<int> nums, vector<int> chosen, vector<vector<int>>& res) {
		if (nums.empty()) {
			res.push_back(chosen);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			nums.erase(nums.begin()+i);
			chosen.push_back(num);
			dfs(nums, chosen, res);
			chosen.pop_back();
			nums.insert(nums.begin()+i, num);
		}
	}

    string getPermutation(int n, int k) {
		if (n == 0) { return ""; }
		if (n == 1) { return "1"; }
		if (n == 2) { return k == 1 ? "12" : "21"; }
		
		vector<int> nums;
		for (int i = 1; i <= n; ++i) {
			nums.push_back(i);
		}
		vector<int> chosen;
		vector<vector<int>> arr;

		dfs(nums, chosen, arr);

		auto item = arr[k-1];
		string res = "";
		for (auto n : item) {
			res += to_string(n);
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.getPermutation(3, 3) << endl;
}

int main() {
	unit_test();
	return 0;
}
