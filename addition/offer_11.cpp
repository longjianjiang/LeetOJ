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

// 给定n，返回二进制形式中1的个数；
class Solution {
public:
     int  NumberOf1(int n) {
		 int res = n & 1;
		 while (n = n << 1) {
			 res += n & 1;
		 }
		 return res;
     }
};
