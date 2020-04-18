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

// 0 1 2 3 4 5 6
// 0 1 1 2 3 5 8
class Solution {
public:
    int Fibonacci(int n) {
		if (n < 0) { return -1; }
		if (n == 0) { return 0; }
		if (n < 3) { return 1; }

		int prev = 0, curr = 1, next = 1;

		for (int i = 3; i <= n; ++i) {
			prev = curr;
			curr = next;
			next = prev + curr;
		}
		return next;
    }
};

void unit_test() {
	Solution s;

	cout << s.Fibonacci(3) << endl;
	cout << s.Fibonacci(5) << endl;
}

int main() {
	unit_test();
	return 0;
}
