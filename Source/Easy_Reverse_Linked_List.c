struct Node
{
	int data;
	struct Node* next;
};

struct Node* ReverseLinkedList(struct Node* head)
{
	struct Node* next = NULL;
	struct Node* current = head;
	struct Node* previous = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	return previous;
}