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

// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

// [ref](https://blog.csdn.net/gatieme/article/details/51485713)

// 1> 使用&&短路性质进行递归求和；
class Solution {
public:
    int Sum_Solution(int n) {
		int res = n;
		n && (res += Sum_Solution(n-1));
		return res;
    }
};
