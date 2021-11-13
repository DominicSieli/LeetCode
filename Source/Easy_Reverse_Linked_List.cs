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
	public Node ReverseLinkedList(Node head)
	{
		Node next = null;
		Node current = head;
		Node previous = null;

		while(current != null)
		{
			next = current.next;
			current.next = previous;
			previous = current;
			current = next;
		}

		return previous;
	}
}