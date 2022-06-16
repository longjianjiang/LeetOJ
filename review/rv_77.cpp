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

// 1234
// 12 i = 1;
//    i = 3;
//    i = 4;
class Solution {
public:
    void dfs(vector<int> nums, vector<int>& chosen, int idx, int k, vector<vector<int>>& res) {
        if (chosen.size() == k) {
            res.push_back(chosen);
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            int num = nums[i];
            chosen.push_back(num);
            dfs(nums, chosen, i+1, k, res);
            chosen.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if (n <= 0) { return {}; }
        if (n == 1) { return {{1}}; }

        vector<int> nums;
        for (int i = 1; i <= n; ++i) { nums.push_back(i); }

        vector<vector<int>> res;
        vector<int> chosen;

        dfs(nums, chosen, 0, k, res);

        return res;
    }
};

void show_arr_one_dimensional(vector<int> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		int num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

void show_arr_two_dimensional(vector<vector<int>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}

void unit_test() {
	Solution s;
	auto res = s.combine(4, 2);
	show_arr_two_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
