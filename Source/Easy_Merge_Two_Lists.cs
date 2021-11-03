using System;

public class Node
{
	public int data;
	public Node next;

	public Node(int data = 0, Node next = null)
	{
		this.data = data;
		this.next = next;
	}
}

public class Solution
{
	public Node MergeTwoListsIterative(Node list1, Node list2)
	{
		Node node = null;
		Node head = null;
		Node tail = null;

		if(list1 != null && list2 == null) return list1;
		if(list1 == null && list2 != null) return list2;

		while(list1 != null && list2 != null)
		{
			node = (list1.data < list2.data) ? list1 : list2;
			if(tail == null) head = node; else tail.next = node; tail = node;
			if(list1.data < list2.data) list1 = list1.next; else list2 = list2.next;
		}

		if(list1 != null) {tail.next = list1; tail = list1;}
		if(list2 != null) {tail.next = list2; tail = list2;}

		return head;
	}

	public Node MergeTwoListsRecursive(Node list1, Node list2)
	{
		if(list1 == null) return list2;
		if(list2 == null) return list1;
		if(list1.data < list2.data) {list1.next = MergeTwoListsRecursive(list1.next, list2); return list1;}
		if(list1.data >= list2.data) {list2.next = MergeTwoListsRecursive(list1, list2.next); return list2;}
		return null;
	}
}

public class LeetCode
{
	public static void Main()
	{
		Node list1 = null;
		Node list2 = null;
		Solution solution = new Solution();

		for(int i = 10; i > 0; i--)
		{
			Node node = new Node(i, list1);
			list1 = node;
		}

		for(int i = 10; i > 0; i--)
		{
			Node node = new Node(i, list2);
			list2 = node;
		}

		Node list = solution.MergeTwoListsIterative(list1, list2);

		while(list != null)
		{
			Console.WriteLine(list.data);
			list = list.next;
		}
	}
}