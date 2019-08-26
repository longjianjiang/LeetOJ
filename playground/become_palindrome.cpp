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

// case "abcb"
string become_palindrome(string s) {
	if (s.size() <= 1) { return s; }

	queue<char> q;
	stack<char> stk;
	int left = 0, right = (int)s.size()-1;
	while (left < right) {
		if (s[left] == s[right]) {
			q.push(s[left]);
			stk.push(s[right]);
		} else {
			int diff = right-left;
			if (diff == 1) {
				q.push(s[right]);
				q.push(s[left]);
				stk.push(s[right]);
			} else {
				q.push(s[left]);
				q.push(s[right]);
				stk.push(s[left]);
				stk.push(s[right]);
			}
		}
		++left; --right;
	}

	bool is_odd = s.size() & 1;
	if (is_odd) {
		int mid = (s.size()-1) / 2;
		q.push(s[mid]);
	}

	string res;
	while (!q.empty()) {
		res += q.front(); q.pop();
	}
	while (!stk.empty()) {
		res += stk.top(); stk.pop();
	}
	return res;
}

string become_palindrome_dp(string s) {
	int nsize = (int)s.size();
	vector<vector<int>> dp(nsize, vector<int>(nsize, 0));
	for (int i = nsize-1; i >= 0; --i) {
		for (int j = 0; j < nsize; ++j) {
			if (i >= j) { 
				dp[i][j] = 0; 
			} else {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i+1][j-1];
				} else { 
					dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
				}
			}
		}
	}

	int usize = nsize + dp[0][nsize-1];
	vector<int> v = dp[0];
	string res(usize, ' ');

	int oi = 0, oj = nsize-1;
	int ni = 0, nj = usize-1;
	while (oi <= oj) {
		if (s[oi] == s[oj]) {
			res[ni++] = res[nj--] = s[oi];
			++oi; --oj;
		} else if (v[oi] < v[oj]) {
			res[ni++] = res[nj--] = s[oi];
			++oi;
		} else {
			res[ni++] = res[nj--] = s[oj];
			--oj;
		}
	}

	return res;
}

void unit_test() {
	vector<string> arr = {"a", "ab", "abc", "abcd", "abca", "abcb"};
	for (auto str: arr) {
		string palindrome = become_palindrome_dp(str);
		cout << palindrome << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
