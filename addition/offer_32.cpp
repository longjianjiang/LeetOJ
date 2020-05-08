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

// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

// 1> 暴力，遍历所有情况，找到最小的数；
// 2> 排序，按规则将数组排序，直接按排序后的元素拼接并返回；
bool numSort(int i, int j) {
	auto getLocListFromNumber = [](int n) -> vector<int> {
		vector<int> res;
		if (n == 0) {
			res.push_back(0);
			return res;
		}
		while (n) {
			res.push_back(n % 10);
			n /= 10;
		}
		return res;
	};
	vector<int> leftList = getLocListFromNumber(i);
	vector<int> rightList = getLocListFromNumber(j);

	int len = min(leftList.size(), rightList.size());
	for (int i = 0; i < len; ++i) {
		if (leftList[i] == rightList[i]) { continue; }
		return leftList[i] < rightList[i];
	}
	return leftList.size() > rightList.size();
}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
		sort(numbers.begin(), numbers.end(), numSort);

		string res;
		for (auto num: numbers) {
			res += to_string(num);
		}
		return res;
    }
};

void unit_test() {
	Solution s;
	vector<int> nums = {3, 32, 321};
	cout << s.PrintMinNumber(nums) << endl;
}

int main() {
	unit_test();
	return 0;
}
