

void helper(TreeNode* root) {
	if (!root) { return; }
	if (!root->left && !root->right) { return; }
	
	auto tmp = root->right;
	root->right = root->left;
	root->left = tmp;

	helper(root->left);
	helper(root->right);
}

TreeNode* invertTree(TreeNode* root) {
	helper(root);
	
	return root;
}
