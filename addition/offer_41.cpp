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
// 2> 双指针遍历；
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum <= 1) { return {}; }

		vector<vector<int>> res;
		for (int i = 1; i <= sum/2; ++i) { // 3 => [1, 2], i <= sum/2
			vector<int> tmp; tmp.push_back(i);
			int cnt = i;

			for (int j = i+1; j < sum; ++j) {
				cnt += j; tmp.push_back(j);
				if (cnt == sum) { res.push_back(tmp); }
				if (cnt > sum) { break; }
			}
		}
		return res;
    }

	int getSum(int start, int end) {
		int res = 0;
		for (int i = start; i <= end; ++i) {
			res += i;
		}
		return res;
	}

	vector<vector<int>> findContinuousSequence(int sum) {
		if (sum <= 2) { return {}; }

		vector<vector<int>> res;
		int left = 1, right = 2;
		while (left <= sum/2 && right < sum) {
			int cnt = getSum(left, right);
			if (cnt < sum) {
				++right;
			} else {
				if (cnt == sum) {
					vector<int> tmp;
					for (int i = left; i <= right; ++i) { tmp.push_back(i); }
					res.push_back(tmp);
				}
				++left; right = left+1;
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
