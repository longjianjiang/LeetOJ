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


struct TrieNode {
	bool is_end = false;
	int idx = -1;
	array<TrieNode *, 26+1> children = { nullptr };
};

bool is_palindrome(string word) {
	int left = 0, right = (int)word.size()-1;
	while (left < right) {
		if (word[left] != word[right]) { return false; }
		++left; --right;
	}
	return true;
}

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
		if (word.empty()) {
			root->children[26] = new TrieNode();
			auto node = root->children[26];
			node->is_end = true;
			node->idx = idx;
			return;
		}
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

	bool is_valid(string word, int pos) {
		int size = (int)word.size()-1;
		if ( pos == size) { return true; }

		char ch = word[++pos];
		while (pos <= size) {
			if (word[pos++] != ch) { return false; }
		}
		return true;
	}

	vector<int> find(const string word, int pos) {
		auto node = root;
		int i = 0, size = (int)word.size()-1;

		vector<int> res;
		while ( i <= size ) {
			int idx = word[i] - 'a';
			if (node->children[idx] == nullptr) {
				return res;
			}
			node = node->children[idx];
			if (node->is_end) { 
				if (node->idx == pos && root->children[26] && is_palindrome(word)) { return {root->children[26]->idx}; }
				if (node->idx !=pos && is_valid(word, i)) {
					res.push_back(node->idx);
				}
			}
			++i;
		}

		if (node->is_end) {
			vector<int> idxs;
			for (int i = 0; i < 26; ++i) {
				if (node->children[i]) { idxs.push_back(i); }
			}

			for (auto idx : idxs) {
				auto child = node->children[idx];
				while (child) {
					if (child->is_end) { 
						res.push_back(child->idx); 
					} 
					child = child->children[idx];
				}
			}

			return res;
		}

		return res;
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
			string str = words[i];
			if (str.empty()) {
				for (int j = 0; j < words.size(); ++j) {
					if (i == j) { continue; }
					if (is_palindrome(words[j])) {
						res.push_back({j, i});
					}
				}
				continue;
			}

			reverse(str.begin(), str.end());
			vector<int> poss = trie->find(str, i);
			if (poss.size()) {
				for (int pos: poss) {
					vector<int> pair = {pos, i};
					res.push_back(pair);
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
}

int main() {
	unit_test();
	return 0;
}
