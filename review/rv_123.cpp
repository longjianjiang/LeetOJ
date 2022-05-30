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

// 两次交易计算最大收益；
// 左右两次计算最值，相加；
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		vector<int> left(nsize, 0);
		vector<int> right(nsize, 0);

		doLeft(prices, left);
		doRight(prices, right);

		int res = 0;
		for (int i = 0; i < nsize; ++i) {
			res = max(res, left[i] + right[i]);
		}
		return res;
    }

	void doLeft(vector<int> prices, vector<int>& left) {
		int nsize = prices.size();

		int res = 0, low = prices[0];
		for (int i = 1; i < nsize; ++i) {
			res = max(res, prices[i] - low);
			left[i] = res;
			low = min(low, prices[i]);
		}
	}

	void doRight(vector<int> prices, vector<int>& right) {
		int nsize = prices.size();

		int res = 0, high = prices[nsize-1];
		for (int i = nsize - 1; i >= 0; --i) {
			res = max(res, high - prices[i]);
			right[i] = res;
			high = max(high, prices[i]);
		}
	}
};

void unit_test() {
	Solution s;

	vector<int> list = {3, 3, 5, 0, 0, 3, 1, 4};
	int res = s.maxProfit(list);
	cout << res << endl;
}

int main() {
	unit_test();
	return 0;
}

