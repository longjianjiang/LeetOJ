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
    string multiply(string num1, string num2) {
		int m = (int)num1.size(), n = (int)num2.size();

		vector<int> res(m+n, 0);
		string resStr = "";
		for (int i = m-1; i >=0; --i) {
			int val1 = num1[i] - '0';
			for (int j = n-1; j >= 0; --j) {
				int num = val1 * (num2[j] - '0');
				int pos1 = i + j, pos2 = i + j + 1;
			}
		}

		return "";

    }
};

int main() {
	Solution s;
	s.multiply("123", "456");
	return 0;
}
