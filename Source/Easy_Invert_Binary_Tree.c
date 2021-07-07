struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode* Invert_Binary_Tree(struct TreeNode* root)
{
	if(root == NULL) return NULL;
    struct TreeNode* left = Invert_Binary_Tree(root->left);
    struct TreeNode* right = Invert_Binary_Tree(root->right);
    root->left = right;
    root->right = left;
    return root;
}