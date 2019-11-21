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

// 给定字符串判断是否符合 "1123" ，1+1=2；1+2=3，长度至少为3；
// 回溯匹配即可；
class Solution {
public:
	bool dfs(string str, vector<long> nums) {
		int nsize = (int)nums.size();
		if (nsize >= 3 && nums[nsize-1] != nums[nsize-2] + nums[nsize-3]) { return false; }
		if (str.empty() && nsize >= 3) { return true; }

		for (int len = 1; len <= str.size(); ++len) {
			string sub = str.substr(0, len);
			if ((sub[0] == '0' && sub.size() != 1) || sub.size() > 19) { continue; }
			string left = str.substr(len);
			nums.push_back(stol(sub));
			if (dfs(left, nums)) { return true; }
			nums.pop_back();
		}
		return false;
	}

    bool isAdditiveNumber(string num) {
		return dfs(num, {});
    }
};

void unit_test() {
	Solution s;

	cout << s.isAdditiveNumber("1123") << endl;
}

int main() {
	unit_test();
	return 0;
}
