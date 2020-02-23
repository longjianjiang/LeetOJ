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

// 1-A ... 26-Z, 27-AA; 给定数字，要求返回对应的字母
class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) { return ""; }
        return convertToTitle((n-1) / 26) + (char)((n-1) % 26 + 'A');
    }

	string convertToTitle_iteration(int n ) {
		string res = "";
		while (n != 0) {
			if (n % 26 == 0) {
				res += 'Z';
				n -= 26;
			} else {
				res += ((n % 26) - 1 + 'A');
				n -= (n % 26);
			}
			n /= 26;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
