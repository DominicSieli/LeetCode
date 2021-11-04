struct Node
{
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int x) : data(x), next(nullptr) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

Node* ReverseLinkedList(Node* head)
{
	Node* current = head;
	Node* next = nullptr;
	Node* previous = nullptr;

	while(current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	return previous;
}