struct ListNode
{
	int val;
	struct ListNode* next;
};


struct ListNode* Reverse_Linked_List(struct ListNode* head)
{
	struct ListNode* next = NULL;
	struct ListNode* current = head;
	struct ListNode* previous = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	return previous;
}