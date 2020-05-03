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

// 输入一个非空整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

// 1> 根据二叉搜索树的性质，左小于根右大于根，后序中得到根，递归的判断左右是否符合这个条件即可；
// 这题牛客网测试用例有问题；
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int nsize = sequence.size();
		if (nsize <= 1) { return true; }

		int root = sequence[nsize-1];
		int i;
		for (i = 0; i < nsize-1; ++i) {
			if (sequence[i] > root) {
				break;
			}
		}
		for (int j = i+1; j < nsize-1; ++j) {
			if (sequence[j] < root) { return false; }
		}
		
		vector<int> left(sequence.begin(), sequence.begin()+i);
		vector<int> right(sequence.begin()+i, sequence.end()-1);

		return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
    }
};
