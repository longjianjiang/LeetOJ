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

// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
// aab => aab, aba, baa 

// 1> dfs，因为存在重复，而且测试用例需要是字典序，所以用set以后转为vector后需要排序后返回；
// 2> dfs, 深搜过程中，增加一个set，for循环时如果某个ch已经出现过，直接跳过；
// 3> 递归，str字符进行swap；
class Solution {
public:
	void dfs(vector<char>& list, vector<char>& chosen, vector<string>& res, int nsize) {
		if (chosen.size() == nsize) {
			string tmp;
			for (auto ch: chosen) { tmp += ch; }
			res.push_back(tmp);
			return;
		}
		unordered_set<char> us;
		for (int i = 0; i < list.size(); ++i) {
			auto ch = list[i];
			if (us.find(ch) != us.end()) { continue; }
			us.insert(ch);
			chosen.push_back(ch);
			list.erase(list.begin()+i);
			dfs(list, chosen, res, nsize);
			chosen.pop_back();
			list.insert(list.begin()+i, ch);
		}
	}

    vector<string> Permutation(string str) {
		if (str.empty()) { return {}; }
		vector<char> list;
		for (auto ch: str) { list.push_back(ch); }

		vector<string> res;
		vector<char> chosen;
		unordered_set<char> us;
		dfs(list, chosen, res, list.size());

		return res;
    }

	void helper(string str, int idx, vector<string>& res) {
		if (idx == str.size()) { res.push_back(str); return; }

		for (int i = idx; i < str.size(); ++i) {
			if (i != idx && str[i] == str[idx]) { continue; }

			swap(str[i], str[idx]);
			helper(str, idx+1, res);
		}
	}

	vector<string> permutation_swap(string str) {
		if (str.empty()) { return {}; }

		vector<string> res;
		helper(str, 0, res);

		return res;
	}
};
