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

// 构造一个Trie
struct TrieNode {
	bool is_end = false;
	array<TrieNode*, 26> children = { nullptr };

	~TrieNode() {
		for (auto child: children) {
			delete child;
			child = nullptr;
		}
	}
};

class Trie {
	TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
		root = new TrieNode();
    }

	~Trie() {
		delete root;
		root = nullptr;
	}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
       	auto node = root;
		for (auto ch: word) {
			int idx = ch - 'a';
			if (node->children[idx] == nullptr) {
				node->children[idx] = new TrieNode();
			} 
			node = node->children[idx];
		}
		node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       	auto node = root;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (node->children[idx] == nullptr) {
				return false;
			}
			node = node->children[idx];
		}
		return node->is_end; // case insert("apple"); search("app")
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       	auto node = root;
		for (auto ch : prefix) {
			int idx = ch - 'a';
			if (node->children[idx] == nullptr) {
				return false;
			}
			node = node->children[idx];
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
