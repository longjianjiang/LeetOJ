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

// "abc" "efabc"
// "ab" "abc"
int findSubstrPos(string s, string p) {
	if (s == p) { return 0; }
	if (p.size() > s.size()) { return -1; }

	int l = 0, r = 0;
	int r2 = 0;
	while (r < s.size()) {
		if (s[r] != p[l]) {
			l = 0;
			r2++;
			r = r2;
		} else {
			r++;
			l++;
			if (l == p.size()) { return r-l; }
		}   
	}
	return -1;
}

void unit_test() {
	cout << findSubstrPos("hello", "ll") << endl;
	cout << findSubstrPos("aaaa", "bba") << endl;
	cout << findSubstrPos("", "") << endl;

	const char *p = "1234";
	cout << sizeof(p) << endl;
	char q[5] = "1234";
	cout << sizeof(q) << endl;
}

int main() {
	unit_test();
	return 0;
}
