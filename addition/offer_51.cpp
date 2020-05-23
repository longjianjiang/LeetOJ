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

// 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
// 输入: [1,2,3,4,5]
// 输出: [120,60,40,30,24]

// 1> 朴素，遍历两段，求结果；超时
// 2> 规律，上下三角求乘积；
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
		vector<int> res;
		int nsize = a.size();

		for (int i = 0; i < nsize; ++i) {
			int leftSeg = i-1 < 0 ? 0 : i-1;
			int rightSeg = nsize-1;
			int leftNum = 1, rightNum = 1;
			for (int j = 0; j <= leftSeg; ++j) {
				int num = i == j ? 1 : a[j];
				leftNum *= num;
			}
			for (int j = i+1; j <= rightSeg; ++j) {
				rightNum *= a[j];
			}
			res.push_back(leftNum*rightNum);
		}

		return res;
    }

	vector<int> constructArr_2(vector<int>& arr) {
		int nsize = arr.size();
		if (nsize <= 1) { return arr; }

		vector<int> res(nsize, 1);
		for (int i = 1; i < nsize; ++i) {
			res[i] = res[i-1] * arr[i-1];
		}
		int tmp = 1;
		for (int i = nsize-2; i >= 0; --i) {
			tmp *= arr[i+1];
			res[i] *= tmp;
		}

		return res;
	}
};

void show_arr_one_dimensional(vector<int> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		int num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

void show_arr_two_dimensional(vector<vector<int>> arr) {
	for (auto v: arr) {
		show_arr_one_dimensional(v);
	}
}

void unit_test() {
	Solution s;
	vector<int> arr = {1, 2, 3, 4, 5};
	auto res = s.constructArr(arr);

	show_arr_one_dimensional(res);
}

int main() {
	unit_test();
	return 0;
}
