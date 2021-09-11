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
 * 给定一个较长字符串big和一个包含较短字符串的数组smalls，设计一个方法，根据smalls中的每一个较短字符串，对big进行搜索。输出smalls中的字符串在big里出现的所有位置positions，其中positions[i]为smalls[i]出现的所有位置。

输入：
big = "mississippi"
smalls = ["is","ppi","hi","sis","i","ssippi"]
输出： [[1,4],[8],[],[3],[1,4,7,10],[5]]
*/

// https://leetcode-cn.com/problems/multi-search-lcci/solution/bao-li-fa-zi-dian-shu-yi-ji-kmpduo-fang-pprn8/

struct TrieNode {
	int wordEndIdx = -1;
	array<TrieNode *, 26> children = { nullptr };
};

class Trie {
private:
	TrieNode *root;

public:
	Trie() {
		root = new TrieNode();
	}

	~Trie() {
		delete root;
		root = nullptr;
	}

	void insert(const string word, int idx) {
		auto node = root;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (node->children[idx] == nullptr) {
				node->children[idx] = new TrieNode();
			}
			node = node->children[idx];
		}
		node->wordEndIdx = idx;
	}

	void search(const string word, int pos, vector<vector<int>>& res) {
		auto node = root;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (node->children[idx] != nullptr) {
				node = node->children[idx];
				if (node->wordEndIdx != -1) {
					res[node->wordEndIdx].push_back(pos);
				}
			} else {
				return;
			}
		}
	}
};

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    	int smallSize = smalls.size(), bigSize = big.size();
        vector<vector<int>> res(smallSize, vector<int>{});

    	Trie *trie = new Trie();
    	for (int i = 0; i < smallSize; ++i) {
    		trie->insert(smalls[i], i);
    	}

		for (int i = 0; i < bigSize; ++i) {
			string substr = big.substr(i);
			trie->search(substr, i, res);
		}

		return res;
    }
};

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
		if (smalls.empty()) { return {}; }

		vector<vector<int>> res;
		for (auto str : smalls) {
			res.push_back(searchPos(big, str));
		}

		return res;
    }

	vector<int> searchPos(string big, string small) {
		if (small.empty() || big.empty()) { return {}; }
		vector<int> res;
		int idx = 0;
		while ((idx = searchPos(big, small, idx)) >= 0) {
			res.push_back(idx);
			idx++;
		}
		return res;
	}

	int searchPos(string big, string small, int index) {
		int bigSize = big.size();
		int smallSize = small.size();

		while (index < bigSize) {
			int pos = 0;
			for (; pos < smallSize; ++pos) {
				int tmp = pos + index;
				if (tmp >= bigSize) { break; }
				if (big[tmp] != small[pos]) { break; }
			}
			if (pos == smallSize) { return index;  }
			index++;
		}

		return -1;
	}
};
