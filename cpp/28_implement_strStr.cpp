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

// 字符串匹配，查找p在s中的索引。
// 使用KMP算法
class Solution {
public:
	int strStr_dfa(string haystack, string needle) {
		if (needle.empty()) { return 0; }

		auto get_dfa = [](string p) {
			vector<vector<int>> dfa(256, vector<int>(p.size(), 0));
			dfa[p[0]][0] = 1;

			int state = 0;
			for (int i = 1; i < p.size(); ++i) {
				for (int j = 0; j < 256; ++j) {
					dfa[j][i] = dfa[j][state];
				}	
				dfa[p[i]][i] = i+1;
				state = dfa[p[i]][state];
			}

			return dfa;
		};

		int i = 0, j = 0;
		int l1 = haystack.size(), l2 = needle.size();
		auto dfa = get_dfa(needle);

		for (; i < l1 && j < l2; ++i) {
			j = dfa[haystack[i]][j];
		}
		if (j == l2) { return i - l2; }
		return -1;
	}

    int strStr(string haystack, string needle) {
		if (needle.empty()) { return 0; }

		auto get_next = [](string p) {
			vector<int> next(p.size(), 0); next[0] = -1;
			int k = -1, j = 0;

			// [0...j] -> [j+1]
			while (j < p.size()-1) {
				if (k == -1 || p[j] == p[k]) {
					if (p[j+1] == p[k+1]) {
						next[++j] = next[++k];
					} else {
						next[++j] = ++k;
					}
				} else {
					k = next[k];
				}
			}

			return next;
		};

		int i = 0, j = 0;
		int l1 = haystack.size(), l2 = needle.size();
        vector<int> next = get_next(needle);
        
		while (i < l1 && j < l2) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++; j++;
			} else {
				j = next[j];
			}
		}

		if (j == l2) { return i - l2; }
		return -1;
    }
};
