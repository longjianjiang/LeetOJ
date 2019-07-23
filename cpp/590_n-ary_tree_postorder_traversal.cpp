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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) { return res; }

        stack<Node *> s;
		s.push(root);

		while (!s.empty()) {
			Node *node = s.top();
			s.pop();

			res.insert(res.begin(), node->val);

			for (auto it = node->children.begin(); it != node->children.end(); ++it) {
				if (*it) { s.push(*it); }
			}
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
