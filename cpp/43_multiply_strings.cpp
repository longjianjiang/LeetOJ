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

// 给定两个数字字符串，要求返回乘积的字符串
// 使用小时候打草稿使用的乘法规则，以 123 * 456 举例
/*
 *		1 2 3
 *		4 5 6
 *		-----
 *		  1 8
 *		1 2
 *		6
 *		-----
 *		7 3 8
 */
// 上面是123 * 6的结果 738；之后是50*123，这个时候加的时候位需要从10位开始加；后面依次类推
// 用一个数组存储乘积的各个位，加的过程是这样的：
// 3*6 = 18，第一次加此时数组[0,0,0,0,1,8]
// 2*6 = 12, 第二次加，这个时候需要首先将12+1，也就是数组idx为1的值，结果是13. 现在可以更新数组，idx为1的位置重新赋值为13%10；后面一位增加13/10；这个时候数组[0,0,0,1,3,8]
// 1*6 = 6, 第三次加，依然首先将6+1，idx为2的值，结果是7。更新数组，idx为2的位置重新赋值为7，后面一位未增加，此时数组为[0,0,0,7,3,8]
// 可以看到是想要的结果738，后面依次累加即可.

class Solution {
public:
    string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty()) { return ""; }
		int m = (int)num1.size(), n = (int)num2.size();

		vector<int> res(m+n, 0);
		string resStr = "";
		for (int i = n-1; i >=0; --i) {
			int val1 = num2[i] - '0';
			for (int j = m-1; j >= 0; --j) {
				int num = val1 * (num1[j] - '0');
				int pos1 = n-i-1 + m-j-1;
				int pos2 = pos1+1;
				int sum = num + res[pos1];
				res[pos1] = sum % 10;
				res[pos2] += sum / 10;
			}
		}

		for(int i = (int)res.size()-1; i >= 0; --i) {
			int num = res[i];
			if (resStr.empty() && num == 0) { continue; }
			resStr += num + '0';
		}

		return resStr.empty() ? "0" : resStr;
    }
};

void unit_test() {
	Solution s;

	assert(s.multiply("123", "456") == "56088");
	assert(s.multiply("0", "0") == "0");
}

int main() {
	unit_test();
	return 0;
}
