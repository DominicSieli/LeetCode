public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    public TreeNode Invert_Binary_Tree(TreeNode root)
    {
        if(root == null) return null;
        TreeNode left = Invert_Binary_Tree(root.left);
        TreeNode right = Invert_Binary_Tree(root.right);
        root.left = right;
        root.right = left;
        return root;
    }
}