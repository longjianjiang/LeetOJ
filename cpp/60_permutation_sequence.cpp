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

// 给定n和k，要求返回n所有组合中第k个；
// 首先求出n*slice，根据k算出page，对page进行求出组合，根据k定位到所在的idx；
class Solution {
public:
	int get_total(int n) {
		int res = 1;
		if (n <= 1) { return res; }
		while (n > 1) {
			res *= n;
			n -= 1;
		}
		return res;
	}

	void dfs(vector<int> nums, vector<int>& chosen, vector<vector<int>>& res) {
		if (nums.empty()) {
			res.push_back(chosen);
		} else {
			for (int i = 0; i < nums.size(); ++i) {
				int n = nums[i];
				chosen.push_back(n);
				nums.erase(nums.begin()+i);
				dfs(nums, chosen, res);
				chosen.pop_back();
				nums.insert(nums.begin()+i, n);
			}
		}
	}

    string getPermutation(int n, int k) {
        if (n == 1) { return "1"; }
		if (n == 2) { return k == 1 ? "12" : "21"; }

		int slice = get_total(n-1);
		int page = (k-1) / slice;

		vector<vector<int>> res;
		vector<int> chosen;
		
		vector<int> nums;
		for (int i = 1; i <= n; ++i) { nums.push_back(i); }

		chosen.push_back(page+1);
		nums.erase(nums.begin()+page);
		dfs(nums, chosen, res);

		string str;
        int idx = (k - page * slice)-1;
		auto vec = res[idx];
		for (auto n : vec) { str += to_string(n); }

		return str;
	}
};

void unit_test() {
	Solution s;

//	cout << s.getPermutation(4, 9) << endl;
//	cout << s.getPermutation(4, 1) << endl;
//	cout << s.getPermutation(3, 1) << endl;
	cout << s.getPermutation(3, 2) << endl;
}

int main() {
	unit_test();
	return 0;
}
