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

// 给定相同长度的字符串数组，要求返回删除最少次数，使得数组成为字典序。
// 需要用额外的数组来记录前面已经是字典序的字符串，当进行字符比较的时候，只有当已经匹配相等同时字符逆序的时候才需要进行删除。
// 需要整体考虑之前匹配的，不能单一的考虑某一列的情况。
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
		int row = (int)(A.size()), col = (int)(A[0].size());

		int res = 0;
		vector<string> b(row, "");
		for (int i = 0; i < col; ++i) {
			bool flag = false;
			for (int j = 0; j < row-1; ++j) {
				if (b[j] == b[j+1] && A[j][i] > A[j+1][i]) {
					flag = true;
				}
			}
			if (flag) {
				++res;
			} else {
				for (int k = 0; k < row; ++k) {
					b[k] = b[k] + A[k][i];
				}
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<string> v1 = {"xc", "yb", "za"};
	vector<string> v2 = {"zyx","wvu","tsr"};
	vector<string> v3 = {"ca","bb","ac"};
	vector<string> v4 = {"xga","xfb","yfa"};
	vector<string> v5 = {"abx","agz","bgc","bfc"};

	cout << s.minDeletionSize(v3) << endl;
	cout << s.minDeletionSize(v1) << endl;
	cout << s.minDeletionSize(v2) << endl;
	cout << s.minDeletionSize(v4) << endl;
	cout << s.minDeletionSize(v5) << endl;
}

int main() {
	unit_test();
	return 0;
}
