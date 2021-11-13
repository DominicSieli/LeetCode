struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

Node* InvertBinaryTree(struct Node* root)
{
	if(root == NULL) return NULL;
	struct Node* left = InvertBinaryTree(root->left);
	struct Node* right = InvertBinaryTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}