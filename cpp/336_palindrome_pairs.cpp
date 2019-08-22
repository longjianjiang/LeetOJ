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


struct TrieNode {
	bool is_end = false;
	int idx = -1;
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
		node->is_end = true;
		node->idx = idx;
	}

	bool is_palindrome(string word) {
		int left = 0, right = (int)word.size()-1;
		while (left < right) {
			if (word[left] != word[right]) { return false; }
			++left; --right;
		}
		return true;
	}

	int find(const string word) {
		if (word.empty() && is_palindrome(word)) {
			return -2;
		}

		auto node = root;
		int i = 0, size = (int)word.size()-1;

		while ( i <= size ) {
			int idx = word[i] - 'a';
			if (node->children[idx] == nullptr) {
				return -1;
			}
			node = node->children[idx];
			if (node->is_end) { break; }
			++i;
		}

		if (i == size) { return node->idx; }
		char ch = word[++i];
		while (i <= size) {
			if (word[i++] != ch) { return -1; }
		}
		return node->idx;
	}

};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
		if (words.empty()) { return {}; }

		Trie *trie = new Trie();
		for (int i = 0; i < words.size(); ++i) {
			trie->insert(words[i], i);
		}

		vector<vector<int>> res;
		for (int i = 0; i < words.size(); ++i) {
			reverse(words[i].begin(), words[i].end());
			int pos = trie->find(words[i]);
			if (pos >= 0 && pos != i) {
				vector<int> pair = {pos, i};
				res.push_back(pair);
			}
		}

		return res;
    }
};

