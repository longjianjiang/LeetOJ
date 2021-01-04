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

// 和121，122类似，交易次数最多两次；
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize == 0) { return 0; }

		vector<int> left(nsize, 0);
		vector<int> right(nsize, 0);

		calLeft(prices, left); 
        calRight(prices, right);

		int res = 0;
		for (int i = 0; i < nsize; ++i) {
			res = max(res, left[i] + right[i]);
		}
		return res;
    }

	void calLeft(vector<int>& prices, vector<int>& left) {
		int nsize = prices.size();
		if (nsize == 0) { return; }

		int res = 0;
		int low = prices[0];

		for (int i = 0; i < nsize; ++i) {
			res = max(res, prices[i] - low);
			left[i] = res;
			low = min(low, prices[i]);
		}
	}

	void calRight(vector<int>& prices, vector<int>& right) {
		int nsize = prices.size();
		if (nsize == 0) { return; }

		int res = 0;
		int high = prices[nsize-1];

		for (int i = nsize-1; i >= 0; --i) {
			res = max(res, high-prices[i]);
			right[i] = res;
			high = max(high, prices[i]);
		}
	}
};

