using System;

public class List_Node
{
    public int val;
    public List_Node next;
    
    public List_Node(int val = 0, List_Node next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public List_Node Add_Two_Numbers(List_Node l1, List_Node l2)
    {
        int carry = 0;
        List_Node node1 = l1;
        List_Node node2 = l2;
        List_Node sumList = new List_Node();
        List_Node current = sumList;

        while(node1 != null || node2 != null)
	    {
            int x = (node1 != null) ? node1.val : 0;
            int y = (node2 != null) ? node2.val : 0;
            int sum = carry + x + y;

            carry = sum / 10;
            current.next = new List_Node(sum % 10);
            current = current.next;

            if(node1 != null) node1 = node1.next;
            if(node2 != null) node2 = node2.next;
        }

        if(carry > 0)
	    {
            current.next = new List_Node(carry);
        }

        return sumList.next;
    }
}

class LeetCode
{
    public static void Main()
    {
        Solution solution = new Solution();
        Console.WriteLine("Success!");
    }
}