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
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) { return res; }

        queue<Node *> q;
        q.push(root);
		int cnt = 1;
        while (!q.empty()) {
			vector<int> v;
			int times = 0;
			for (int i = 0; i < cnt; ++i) {
				Node *node = q.front();
				q.pop();

				v.push_back(node->val);
				for (auto it = node->children.begin(); it != node->children.end(); ++it) {
					if (*it) { q.push(*it); ++times; }
				}
			}
			cnt = times;
			res.push_back(v);
        }

		return res;
    }
};

void unit_test() {
	Solution s;
}

int main() {
	unit_test();
	return 0;
}
