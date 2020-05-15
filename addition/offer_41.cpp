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

// 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

// 1> 穷举；
// 10
// 1-2-3-4
// 1-3-4-5
// 1-4-5
// 1-5-6
// 1-6-7
// 1-7-8
// 1-8-9
// 1-9
// 2-3-4-5
// 2-4-5
// 2-5-6
// 2-6
// 2-7
// 2-8
// 3-4-5
// 3-5
// 3-6
// 3-7
// 4-5
// 4-6
// 5-6
// 6
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum <= 1) { return {}; }

		vector<vector<int>> res;
		for (int i = 1; i < sum/2; ++i) {
			int start = i+1, end = sum-i;
			vector<int> tmp; tmp.push_back(i);
			int cnt = i;

			while (start <= end) {
				for (int j = start; j <= end; ++j) {
					cnt += j; tmp.push_back(j);
					if (cnt == sum) { res.push_back(tmp); }
					if (cnt > sum) { break; }
				}
				++start;
				cnt = i;
				tmp.clear(); tmp.push_back(i);
			}
		}
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

	auto res = s.FindContinuousSequence(10);
	show_arr_two_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
