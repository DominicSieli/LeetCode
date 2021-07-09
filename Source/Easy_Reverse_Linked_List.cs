public class ListNode
{
    public int val;
    public ListNode next;
    
    public ListNode(int val=0, ListNode next=null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public ListNode Reverse_Linked_List(ListNode head)
    {
        ListNode next = null;
        ListNode current = head;
        ListNode previous = null;

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