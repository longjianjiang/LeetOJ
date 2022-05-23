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
				res = max(res, prices[r] - prices[l]);
			}
			++r;
		}

		return res;
	}
};
