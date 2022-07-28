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
    vector<int> getRow(int rowIndex) {
		if (rowIndex < 0) { return {}; }
		vector<vector<int>> arr;
		arr.push_back({1});
		arr.push_back({1, 1});
		if (rowIndex <= 1) { return arr[rowIndex]; }

		int cnt = rowIndex - 1;
		while (cnt) {
            vector<int> tmp = arr.back();

			vector<int> added;
			added.push_back(1);
			for (int i = 0; i < tmp.size()-1; ++i) {
				int sum = tmp[i] + tmp[i+1];
				added.push_back(sum);
			}
			added.push_back(1);

			arr.push_back(added);

			--cnt;
		}
		return arr[rowIndex];
    }
};
