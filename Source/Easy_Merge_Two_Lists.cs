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
	public ListNode Merge_Two_Lists(ListNode l1, ListNode l2)
	{
		ListNode node = null;
		ListNode head = null;
		ListNode tail = null;

		if(l1 != null && l2 == null) return l1;
		if(l1 == null && l2 != null) return l2;

		while(l1 != null && l2 != null)
		{
			node = (l1.val < l2.val) ? l1 : l2;
			if(tail == null) head = node; else tail.next = node; tail = node;
			if(l1.val < l2.val) l1 = l1.next; else l2 = l2.next;
		}

		if(l1 != null) {tail.next = l1; tail = l1;}
		if(l2 != null) {tail.next = l2; tail = l2;}

		return head;
	}
}

public class LeetCode
{
	public static void Main()
	{
		ListNode l1 = null;
		ListNode l2 = null;
		Solution solution = new Solution();

		for(int i = 10; i > 0; i--)
		{
			ListNode node = new ListNode(i, l1);
			l1 = node;
		}

		for(int i = 10; i > 0; i--)
		{
			ListNode node = new ListNode(i, l2);
			l2 = node;
		}

		ListNode list = solution.Merge_Two_Lists(l1, l2);

		while(list != null)
		{
			Console.WriteLine(list.val);
			list = list.next;
		}
	}
}