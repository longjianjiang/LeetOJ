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
	// 计算整个排列结果，数组取下标会超时；
	// 用索引进行累加，当到k时就可以不用继续了；
	// TODO: nums不加引用，会超时?
	void dfs(vector<int>& nums, vector<int>& chosen, int k, int& idx) {
		if (nums.empty()) {
			cout << "empty" << endl;
			++idx;
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			nums.erase(nums.begin()+i);
			chosen.push_back(num);
			dfs(nums, chosen, k, idx);

			if (idx == k) { return; }
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
		int idx;
		dfs(nums, chosen, k, idx);

		string res("");
		for (auto n : chosen) {
			res += to_string(n);
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.getPermutation(3, 6) << endl;
}

int main() {
	unit_test();
	return 0;
}
