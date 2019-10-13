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
    bool canMeasureWater(int x, int y, int z) {
		return z == 0 || (x+y >=z && z % gcd(x, y) == 0);
    }

	int gcd(int x, int y) {
		return y == 0 ? x : gcd(y, x%y);
	}
};


void unit_test() {
	Solution s;

	int x = 3, y = 5;
	cout << gcd(x, y) << endl;
}

int main() {
	unit_test();
	return 0;
}
