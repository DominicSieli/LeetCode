struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* Reverse_Linked_List(ListNode* head)
{
	ListNode* current = head;
	ListNode* next = nullptr;
	ListNode* previous = nullptr;

	while(current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	return previous;
}