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

// 给定字符串s和子串数组words，要求查找s中包含words所有单词的子串，顺序不做要求，最后返回开始的索引集合。
// 使用map记录子串的数量关系，遍历单词，滑动窗口进行寻找。
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) { return {}; }
        int len = words[0].size(), n = s.size(), cnt = words.size();

        unordered_map<string, int> wordsMap;
        for (auto word: words) {
            wordsMap[word]++;
        }

		vector<int> res;
		int total = 0;
		for (int i = 0; i < len; ++i) {
			total = cnt;
			unordered_map<string, int> dict = wordsMap;
			for (int j = i; j <= n - len; j += len) {
				string sub = s.substr(j, len);
				if (dict[sub]-- > 0) { --total; }
				if ( j >= cnt * len) {
					string word = s.substr(j - cnt*len, len);
					if (++dict[word] > 0) { ++total; }
				}
				if (total == 0) { res.push_back(j - (cnt-1)*len); }
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;

	string str = "barfoothefoobarman";
	vector<string> words = {"foo", "bar"};

	auto res = s.findSubstring(str, words);

	for (auto idx: res) {
		cout << idx << endl;
	}
}

int main() {
	unit_test();
	return 0;
}
