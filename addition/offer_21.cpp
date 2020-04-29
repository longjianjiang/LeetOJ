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
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

// 12345
// 35421
// 用栈来思考，用一个栈来记录需要pop的idx，如果序列中idx小于top，那么直接false；
// 需要额外考虑两个序列中pop的元素是否相等，不相等直接false；
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		int nsize = pushV.size();

		unordered_map<int, int> dict;
		for (int i = 0; i < nsize; ++i) {
			dict[pushV[i]] = i+1;
		}
		stack<int> bePopList;
		int stackFirst = 0; // 记录开始的位置；
		
		for (int i = 0; i < nsize; ++i) {
			int idx = dict[popV[i]];
			if (idx == 0) { return false; }
			--idx;

			if (bePopList.empty()) {
				for (int j = stackFirst; j < idx; ++j) { bePopList.push(j); }
				stackFirst = idx+1;
			} else {
				if (bePopList.top() == idx) {
					bePopList.pop();
				} else if (idx > bePopList.top()) {
					for (int j = stackFirst; j < idx; ++j) { bePopList.push(j); }
					stackFirst = idx+1;
				} else {
					return false;
				}
			}
		}

		return true;
    }
};
