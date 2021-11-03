struct Node
{
	int data;
	Node* left;
	Node* right;
	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(int x) : data(x), left(nullptr), right(nullptr) {}
	Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
};

Node* InvertBinaryTree(Node* root)
{
	if(root == nullptr) return nullptr;
	Node* left = InvertBinaryTree(root->left);
	Node* right = InvertBinaryTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}