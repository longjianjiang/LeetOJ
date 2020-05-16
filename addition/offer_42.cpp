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

// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

// 1> map; 
// 2> two pointer; 
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		int min = INT_MAX;
		vector<int> res;
		unordered_map<int, int> dict;
		for (int i = 0; i < array.size(); ++i) {
			int num = array[i];
			if (dict.find(sum-num) != dict.end()) {
				vector<int> tmp;
				tmp.push_back(num);
				tmp.push_back(sum-num);
				int product = tmp[0]*tmp[1];
				if (product < min) {
					min = product;
					res = tmp;
				}
			}
			dict[num] = i;
		}
		sort(res.begin(), res.end());
		return res;
    }

	vector<int> findNumberWithSum(vector<int> array, int sum) {
		int nsize = array.size();
		vector<int> res;
		if (nsize < 2) { return res; }

		int left = 0, right = nsize-1;
		while (left != right) {
			int cnt = array[left]+array[right];
			if (cnt == sum) {
				res.push_back(array[left]);
				res.push_back(array[right]);
				break;
			} else if (cnt < sum) {
				++left;
			} else {
				--right;
			}
		}

		return res;
	}
};
