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

/*
   输入: candidates = [2,3,6,7], target = 7
   输出: [[7],[2,2,3]]
*/

class Solution {
public:
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

	void dfs(vector<vector<int>>& res, vector<int>& chosen, vector<int> candidates, int idx, int right, int target) {
		if (idx > right || target < 0) { return; }
		if (target == 0) {
			res.push_back(chosen);
			return;
		}
		for (int i = idx; i <= right; ++i) {
			int num = candidates[i];
			target -= num;
			chosen.push_back(num);

			dfs(res, chosen, candidates, i, right, target);

			target += num;
			chosen.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		int right = getValidRightIndex(candidates, target);

		vector<vector<int>> res;
		vector<int> chosen;
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
	Solution s;
	vector<int> candidates = {2, 3, 6, 7};
	auto res = s.combinationSum(candidates, 7);

	show_arr_two_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
