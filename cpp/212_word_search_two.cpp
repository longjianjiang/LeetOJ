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
	vector<pair<int, int>> edges = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:

	void dfs(vector<vector<char>>& board, TrieNode* node,  int x, int y, string& chosen, vector<string>& us) {
		int h = (int)board.size();
		int w = (int)board[0].size();

        int idx = (int)(board[x][y] - 'a');
		if (node->children[idx] == nullptr) { return; }
		node = node->children[idx];

        chosen.push_back(board[x][y]);
        if (node->is_end) {
            us.push_back(chosen);
            node->is_end = false; // case ['a'] ["a", "a"]
        }

		// replace marks flag
        board[x][y] = '$';
        for (auto edge : edges) {
            int nx = x+edge.first, ny = y+edge.second;
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) { continue; }
            if (board[nx][ny] == '$') { continue; }
            dfs(board, node, nx, ny, chosen, us);
        }
        board[x][y] = chosen.back();
        chosen.pop_back();
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

		vector<string> us;
		string chosen;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				dfs(board, trie->get_root(), i, j, chosen, us);
			}
		}

		return us;
    }
};


