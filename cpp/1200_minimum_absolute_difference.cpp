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
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
	    if (arr.size() <= 1) { return {}; }

		sort(arr.begin(), arr.end());
		if (arr.size() == 2) { return {arr}; }

		vector<vector<int>> res;
		int diff = abs(arr[1]-arr[0]);
		res.push_back({arr[0], arr[1]});

		for (int i = 2; i < arr.size(); ++i) {
			int tmp = abs(arr[i]-arr[i-1]);
			if (tmp > diff) { continue; }
			if (tmp < diff) {
				diff = tmp;
				res.clear();
			}
			res.push_back({arr[i-1], arr[i]});
		}

		return res;
    }
};
