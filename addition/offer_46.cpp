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

// 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

// [0, 1, 2, 3, 4]
// [0, 1, 3, 4]

// 1> 朴素，创建数组依次进行取余，直到数组中只有一个元素返回；超时；
// 2> https://blog.csdn.net/wuzhekai1985/article/details/6628491
class Solution {
public:
    int lastRemaining(int n, int m) {
		vector<int> arr;
		for (int i = 0; i < n; ++i) { arr.push_back(i); }

		int idx = 0;
		while (arr.size() > 1) {
			idx += m-1;
			int deletedIdx = idx % arr.size();
			arr.erase(arr.begin()+deletedIdx);
			idx = deletedIdx;
		}

		return arr[0];
    }
};

void unit_test() {
	Solution s;

	cout << s.lastRemaining(5, 3) << endl;
	cout << s.lastRemaining(10, 17) << endl;
}

int main() {
	unit_test();
	return 0;
}
