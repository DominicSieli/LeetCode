using System;

public class ListNode
{
    public int val;
    public ListNode next;

    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        int carry = 0;
        ListNode node1 = l1;
        ListNode node2 = l2;
        ListNode sumList = new ListNode();
        ListNode current = sumList;

        while(node1 != null || node2 != null)
	    {
            int x = (node1 != null) ? node1.val : 0;
            int y = (node2 != null) ? node2.val : 0;
            int sum = carry + x + y;

            carry = sum / 10;
            current.next = new ListNode(sum % 10);
            current = current.next;

            if(node1 != null) node1 = node1.next;
            if(node2 != null) node2 = node2.next;
        }

        if(carry > 0)
	    {
            current.next = new ListNode(carry);
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