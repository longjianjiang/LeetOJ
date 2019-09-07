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
123456

1   5
2 4 6
3 

152463
*/

// 要求所上图，给定行数，按zigzag的排列，最后按行返回。
// 建n个数组，没列进行添加，最后构建字符串

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows <= 1) { return s; }
	
		int nsize = (int)s.size();
		vector<vector<char>> arr(numRows, vector<char>());
		
		bool flag = true;
		int idx = 0;
		while (idx < nsize) {
			if (flag) {
				int cnt = 0;
				while (cnt < numRows) {
					if (idx == nsize) { break; }
					arr[cnt++].push_back(s[idx++]);
				}
			} else {
				int cnt = numRows-2;
				while (cnt > 0) {
					if (idx == nsize) { break; }
					arr[cnt--].push_back(s[idx++]);
				}
			}
			flag = !flag;
		}

		string res;

		for (auto list : arr) {
			for (auto ch : list) {
				res += ch;
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.convert("PAYPALISHIRING", 4) << endl;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
}

int main() {
	unit_test();
	return 0;
}
