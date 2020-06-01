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

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
// 设计一个算法将二叉树进行序列化和反序列化；

// 使用层序遍历的方式进行序列化，首先序列化就是层序遍历，用逗号分隔；
// 反序列化先用逗号分隔拆分成数组，然后使用队列依次添加节点的左右子树，因为存储的是完全二叉树，所以任意节点的left为2*idx+1, right为2*idx+2；
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) { return ""; }

        vector<string> arr = {to_string(root->val)};
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node->left) {
                arr.push_back(to_string(node->left->val));
                q.push(node->left);
            } else {
                arr.push_back("null");
            }

            if (node->right) {
                arr.push_back(to_string(node->right->val));
                q.push(node->right);
            } else {
                arr.push_back("null");
            }
        }

        int idx = arr.size()-1;
        int deletedStartIdx = -1;
        while (idx >= 0) {
            if (arr[idx] == "null") {
                deletedStartIdx = idx;
            } else {
                break;
            }
            --idx;
        }
        if (deletedStartIdx > 0) {
            arr.erase(arr.begin()+deletedStartIdx, arr.end());
        }

        string res = "";
        for (int i = 0; i < arr.size(); ++i) {
            res += arr[i];
            if (i < arr.size()-1) { res += ","; }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) { return NULL; }

        vector<string> arr;
        string delimiter = ",";
        int pos = 0;
        string token;
        while ((pos = data.find(delimiter)) != string::npos) {
            token = data.substr(0, pos);
            arr.push_back(token);
            data.erase(0, pos+delimiter.length());
        }
        arr.push_back(data);

        int idx = 0, nsize = arr.size();
        TreeNode *root = new TreeNode(stoi(arr[idx]));
        auto node = root;
        queue<TreeNode *> q; q.push(node);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            int leftIdx = 2*idx+1, rightIdx = 2*idx+2;
            if (leftIdx < nsize) {
                string leftStr = arr[leftIdx];
                if (leftStr == "null") {
                    node->left = NULL;
                } else {
                    auto tmp = new TreeNode(stoi(leftStr));
                    node->left = tmp;
                    q.push(tmp);
                }
            }
            if (rightIdx < nsize) {
                string rightStr = arr[rightIdx];
                if (rightStr == "null") {
                    node->right = NULL;
                } else {
                    auto tmp = new TreeNode(stoi(rightStr));
                    node->right = tmp;
                    q.push(tmp);
                }
            }
            ++idx;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main(int argc, const char * argv[]) {

    auto one = new TreeNode(1);
    auto two = new TreeNode(2);
    auto three = new TreeNode(3);
    auto four = new TreeNode(4);
    auto five = new TreeNode(5);
    
    one->left = two; one->right = three;
    three->left = four; three->right = five;
    
    auto cc = Codec();
    auto str = cc.serialize(one);
    cout << str << endl;
    
    auto res = cc.deserialize(str);
    
    return 0;
}
