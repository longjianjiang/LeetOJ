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

// 给定x, y, 要求返回x异或y的值中有多少个1.
// mask 按位遍历即可。
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
		int cnt = 0;
		long mask = 1;
		while (mask <= z) {
			if (mask & z) { ++cnt; }
			mask <<= 1;
		}

		return cnt;
    }
};

void unit_test() {
	Solution s;

	cout << s.hammingDistance(1, 4) << endl;
}

int main() {
	unit_test();
	return 0;
}
