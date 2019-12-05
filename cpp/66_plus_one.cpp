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
    vector<int> plusOne(vector<int>& digits) {
		vector<int> res;
		int carry = 0;
		for (int i = digits.size()-1; i >= 0; --i) {
			int num = (i == digits.size()-1) ? digits[i]+1 : digits[i];
			num += carry;
			res.insert(res.begin(), num % 10);
			carry = num / 10;
		}
		if (carry > 0) { res.insert(res.begin(), 1); }
		return res;
    }
};
