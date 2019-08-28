#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool is_palindrome(string word) {
	int left = 0, right = (int)word.size()-1;
	while (left < right) {
		if (word[left] != word[right]) { return false; }
		++left; --right;
	}
	return true;
}

// 给定一个字符串数组，元素不重复，找出两两拼接是回文的下标元组。
// 首先将字符串倒序存入map，遍历数组，拆分字符串s.substr(0,i) s.substr(i),
// 如果其中一个本身就是回文，另一个map中存在，则可以构成回文，
// 最后额外处理一下["", "b"]这种case
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
		if (words.empty()) { return {}; }

		vector<vector<int>> res;
		unordered_map<string, int> dict;
		for (int i = 0; i < words.size(); ++i) {
			string word = words[i];
			reverse(word.begin(), word.end());
			dict[word] = i;
		}

		// case ""
		if (dict.find("") != dict.end()) {
			int pos = dict[""];
			for (int i = 0; i < words.size(); ++i) {
				if (i != pos && is_palindrome(words[i])) {
					res.push_back({pos, i});
				}
			}
		}

		for (int i = 0; i < words.size(); ++i) {
			string word = words[i];
			int nsize = (int)word.size();
			for (int j = 0; j < nsize; ++j) {
				string left = word.substr(0, j);
				string right = word.substr(j);
				
				if (is_palindrome(left) && dict.find(right) != dict.end() && dict[right] != i) {
					res.push_back({dict[right], i});
				}

				if (is_palindrome(right) && dict.find(left) != dict.end() && dict[left] != i) {
					res.push_back({i, dict[left]});
				}
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<string> words = {"a", "b", "c", "ab", "ac", "aa"};
	auto res = s.palindromePairs(words);

	for (auto pair : res) {
		cout << "(" << pair[0] << ", " << pair[1] << ")\n";
	}

	words = {"a", "aa", "aaa"};
	res = s.palindromePairs(words);

	cout << "xxxxxxxxxxxxxxxxxxx\n";
	for (auto pair : res) {
		cout << "(" << pair[0] << ", " << pair[1] << ")\n";
	}

	words = {"abcd", "dcba", "lls", "s", "sssll"};
	res = s.palindromePairs(words);

	cout << "xxxxxxxxxxxxxxxxxxx\n";
	for (auto pair : res) {
		cout << "(" << pair[0] << ", " << pair[1] << ")\n";
	}

	words = {"aba", "a", "ba", "caba"};
	res = s.palindromePairs(words);

	cout << "xxxxxxxxxxxxxxxxxxx\n";
	for (auto pair : res) {
		cout << "(" << pair[0] << ", " << pair[1] << ")\n";
	}
}

int main() {
	unit_test();

	vector<int> arr = {1, 5, 2, 7, 3};
	sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
			return a < b;
	});

	for (auto num : arr) {
		cout << num << endl;
	}
	return 0;
}
