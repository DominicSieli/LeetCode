struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* Invert_Binary_Tree(TreeNode* root)
{
	if(root == nullptr) return nullptr;
	TreeNode* left = Invert_Binary_Tree(root->left);
	TreeNode* right = Invert_Binary_Tree(root->right);
	root->left = right;
	root->right = left;
	return root;
}