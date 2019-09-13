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
Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
*/

/*
2 3 4 5
* - *

2 1 1
- -

1 2
+

1 2 3 4 5
- + * + 
*/

class Solution {
	unordered_map<string, vector<int>> dict;

public:
    vector<int> diffWaysToCompute(string input) {
		if (dict.find(input) != dict.end()) { return dict[input]; }
		vector<int> res;
	
		for (int i = 0; i < input.size(); ++i) {
			// 以每个符号进行拆分成左右两边，left operator right
			if (input[i] == '*' || input[i] == '+' || input[i] == '-') {
				vector<int> left = diffWaysToCompute(input.substr(0, i));
				vector<int> right = diffWaysToCompute(input.substr(i+1));

				for (int k = 0; k < left.size(); ++k) {
					for (int e = 0; e < right.size(); ++e) {
						if (input[i] == '*') {
							res.push_back(left[k] * right[e]);
						} else if (input[i] == '+') {
							res.push_back(left[k] + right[e]);
						} else {
							res.push_back(left[k] - right[e]);
						}
					}
				}
			}
		}

		if (res.empty()) { res.push_back(stoi(input)); }
		dict[input] = res;
		return res;
    }
};

int main() {
	vector<int> nums = {1, 3, 5, 7};

	vector<int> nums2 = {nums.begin()+1, nums.end()};
	for (auto num : nums2) {
		cout << num << endl;
	}
	return 0;
}
