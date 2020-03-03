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

// 给定长度相同的4个数组，要求返回四元组中和为0的个数；
/*
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

// 使用hastTable；
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int nsize = A.size();

		unordered_map<int, int> ab, cd;
		for (int i = 0; i < nsize; ++i) {
			for (int j = 0; j < nsize; ++j) {
				++ab[A[i]+B[j]];
				++cd[C[i]+D[j]];
			}
		}

		int res = 0;
		for(auto item: ab) {
			int num = -item.first;
			res += item.second * cd[num];
		}
		return res;
    }
};
