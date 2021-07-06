struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode* Invert_Binary_Tree(struct TreeNode* root)
{
	if(root == NULL) return NULL;
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}