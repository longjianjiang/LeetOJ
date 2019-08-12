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

// 类似word search 1，还是一个二维字符矩阵，这次给定words数组，要求返回在矩阵中存在的word。
// 建一个Trie，依然对矩阵的每个节点进行深搜回溯
struct TrieNode {
	bool is_end = false;
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

	void insert(const string word) {
		auto node = root;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (node->children[idx] == nullptr) {
				node->children[idx] = new TrieNode();
			}
			node = node->children[idx];
		}
		node->is_end = true;
	}

	TrieNode *get_root() const { return root; }
};

class Solution {
public:

	void dfs(vector<vector<char>>& board, TrieNode* node, vector<vector<bool>>& marks, int x, int y, int w, int h, string chosen, unordered_set<string>& us) {
		if (x < 0 || y < 0 || x >= h || y >= w) { return; }
		if (marks[x][y]) { return; }

		char c = board[x][y];
		chosen += c;
		TrieNode *child = node->children[c - 'a'];
		if (child == nullptr) {
			return;
		} else {
			if (child->is_end) { us.insert(chosen); }
			node = child;
		}

		marks[x][y] = true;
		dfs(board, node, marks, x+1, y, w, h, chosen, us);
		dfs(board, node, marks, x-1, y, w, h, chosen, us);
		dfs(board, node, marks, x, y+1, w, h, chosen, us);
		dfs(board, node, marks, x, y-1, w, h, chosen, us);
		marks[x][y] = false;
	}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int h = (int)board.size();
		if (h == 0) { return {}; }
		int w = (int)board[0].size();
		if (w == 0) { return {}; }

		Trie *trie = new Trie();
		for (auto word : words) {
			trie->insert(word);
		}

		vector<vector<bool>> marks(h, vector(w, false));
		unordered_set<string> us;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				dfs(board, trie->get_root(), marks, i, j, w, h, "", us);
			}
		}

		return {us.begin(), us.end()};
    }
};


