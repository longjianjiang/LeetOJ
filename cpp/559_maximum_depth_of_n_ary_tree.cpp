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
// 类似104，只是这题不一定是二叉树，思路还是一样的
class Solution {
public:
    void dfs(Node* node, int depth, int& maxDepth) {
        if (!node) { return; }
        maxDepth = max(depth, maxDepth);
        
         for (Node* child : node->children) {
             dfs(child, depth+1, maxDepth);
        }
    }
    
    int maxDepth_dfs(Node* root) {
        int maxDepth = 0;
        dfs(root, 1, maxDepth);
        return maxDepth;
    }
    
    int maxDepth_recursive(Node* root) {
        if (!root) { return 0; }
        int height = 0;
        for (auto node : root->children) {
            height = max(height, maxDepth(node));
        }
        return 1 + height;
    }
    
    int maxDepth_bfs(Node* root) {
        if (!root) { return 0; }
        if (root->children.empty()) { return 1; }
        queue<Node *> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {
            depth++;
            auto size = q.size();
            
            for(int i = 0; i < size; ++i) {
                Node *node = q.front();
                q.pop();
                
                for(auto child : node->children) {
                    if (child) { q.push(child); }
                }
            }
        }
        
        return depth;
    }
};
