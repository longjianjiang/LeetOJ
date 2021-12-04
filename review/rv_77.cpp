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
	void dfs(vector<vector<int>>& res, vector<int> chosen, vector<int> nums, int count, int idx) {
        if (chosen.size() == count) {
            res.push_back(chosen);
            return;
        }
        int nsize = nums.size();
        if (idx >= nsize || chosen.size() > count) { return; }
        for (int i = idx; i < nsize; ++i) {
            int num = nums[i];
            chosen.push_back(num);
            dfs(res, chosen, nums, count, i+1);
            chosen.pop_back();
        }
	}

    vector<vector<int>> combine(int n, int k) {
		vector<int> nums;
		for (int i = 1; i <= n; ++i) {
			nums.push_back(i);
		}

		vector<vector<int>> res;
		vector<int> chosen;
		dfs(res, chosen, nums, k, 0);

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
