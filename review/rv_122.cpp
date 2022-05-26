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
    int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int l = 0, r = 1;
		int res = 0;
		while (r < nsize) {
			if (prices[l] > prices[r]) {
				l = r;
			} else {
				if (r+1 < nsize && prices[r+1] < prices[r]) {
					res += prices[r] - prices[l];
					l = r;
				}
			}
			++r;
		}
		// [7, 1, 5, 3, 6, 4]
		// [1, 2, 3, 4]
		res += prices[r-1] - prices[l];

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> arr1 = {7, 1, 5, 3, 6, 4};
	vector<int> arr2 = {1, 2, 3, 4};

	cout << s.maxProfit(arr1) << endl;
	cout << s.maxProfit(arr2) << endl;
}

int main() {
	unit_test();
	return 0;
}
