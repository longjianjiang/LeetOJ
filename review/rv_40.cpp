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
	int getRightIndex(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target) {
                return i - 1;
            } else if (nums[i] == target) {
                return i;
            }
        }
        return (int)(nums.size()-1);
	}

	void dfs(vector<vector<int>>& res, vector<int> chosen, vector<int> candidates, int idx, int right, int target) {
		if (target == 0) {
			res.push_back(chosen);
			return;
		}

		if (target < 0 || idx > right) { return; }
		for (int i = idx; i <= right; ++i) {
			// [1, 1, 2, 5, 6, 7, 10], 过滤掉idx=0, i=1时，重复的[1,2,5], [1,7]
            if (i > idx && candidates[i] == candidates[i-1]) { continue; }
			int num = candidates[i];
			target -= num;
			chosen.push_back(num);
			dfs(res, chosen, candidates, i+1, right, target);
			target += num;
			chosen.pop_back();
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> chosen;
		int right = getRightIndex(candidates, target);
		dfs(res, chosen, candidates, 0, right, target);

		return res;
    }
};

template<typename T>
void show_arr_one_dimensional(vector<T> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		T num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

template<typename T>
void show_arr_two_dimensional(vector<vector<T>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}
void unit_test() {
	// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
	Solution s;
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	auto res = s.combinationSum2(candidates, 8);
	
	show_arr_one_dimensional(candidates);
	show_arr_two_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
