public class Node
{
	public int data;
	public Node left;
	public Node right;

	public Node(int x = 0, Node left = null, Node right = null)
	{
		this.data = x;
		this.left = left;
		this.right = right;
	}
}

public class Solution
{
	public Node InvertBinaryTree(Node root)
	{
		if(root == null) return null;
		Node left = InvertBinaryTree(root.left);
		Node right = InvertBinaryTree(root.right);
		root.left = right;
		root.right = left;
		return root;
	}
}