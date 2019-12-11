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
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows <= 0) { return res; }
		res.push_back({1});
		if (numRows == 1) { return res; }
		res.push_back({1, 1});
		if (numRows == 2) { return res; }

		int cnt = numRows - 2;
		while (cnt-->0) {
			auto last = res.back();
			vector<int> added = {1};
			for (int i = 1; i < last.size(); ++i) {
				added.push_back(last[i]+last[i-1]);
			}
			added.push_back(1);
			res.push_back(added);
		}
		return res;
	}
};

void show_arr_one_dimensional(vector<int> arr) {
	for (auto num: arr) {
		cout << num << " ";
	}
	cout << endl;
}

void show_arr_two_dimensional(vector<vector<int>> arr) {
	for (auto v: arr) {
		cout << "[";
		for (auto num: v) {
			cout << num << " ";
		}
		cout << "]\n";
	}
}

void unit_test() {
	Solution s;
	auto res = s.generate(5);
	show_arr_two_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
