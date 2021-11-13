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
	public Node AddTwoNumbers(Node list1, Node list2)
	{
		int carry = 0;
		Node node1 = list1;
		Node node2 = list2;
		Node list = new Node();
		Node pointer = list;

		while(node1 != null || node2 != null)
		{
			int x = (node1 != null) ? node1.data : 0;
			int y = (node2 != null) ? node2.data : 0;
			int sum = carry + x + y;

			carry = sum / 10;
			pointer.next = new Node(sum % 10);
			pointer = pointer.next;

			if(node1 != null) node1 = node1.next;
			if(node2 != null) node2 = node2.next;
		}

		if(carry > 0)
		{
			pointer.next = new Node(carry);
		}

		return list.next;
	}
}

public class LeetCode
{
	public static void Main()
	{
		Node sum;
		Node pointer;
		Node list1 = new Node();
		Node list2 = new Node();
		Solution solution = new Solution();

		int i = 0;
		pointer = list1;
		while(i < 8)
		{
			i++;
			pointer.next = new Node();
			pointer = pointer.next;
		}

		i = 0;
		pointer = list2;
		while(i < 8)
		{
			i++;
			pointer.next = new Node();
			pointer = pointer.next;
		}

		i = 1;
		pointer = list1;
		while(pointer != null)
		{
			pointer.data = i++;
			pointer = pointer.next;
		}

		i = 1;
		pointer = list2;
		while(pointer != null)
		{
			pointer.data = i++;
			pointer = pointer.next;
		}

		sum = solution.AddTwoNumbers(list1, list2);

		pointer = list1;
		while(pointer != null)
		{
			Console.Write("{0}", pointer.data);
			pointer = pointer.next;
		}

		Console.Write("\n");

		pointer = list2;
		while(pointer != null)
		{
			Console.Write("{0}", pointer.data);
			pointer = pointer.next;
		}

		Console.Write("\n");

		pointer = sum;
		while(pointer != null)
		{
			Console.Write("{0}", pointer.data);
			pointer = pointer.next;
		}
	}
}