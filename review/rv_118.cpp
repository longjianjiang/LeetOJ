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
		while (cnt) {
			vector<int> last = res.back();

			vector<int> arr;
			arr.push_back(1);
			for (int i = 0; i < last.size()-1; ++i) {
				int sum = last[i] + last[i+1];
				arr.push_back(sum);
			}
			arr.push_back(1);

			res.push_back(arr);

			--cnt;
		}
		return res;
    }
};
