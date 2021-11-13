#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int x) : data(x), next(nullptr) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

Node* AddTwoNumbers(Node* list1, Node* list2)
{
	int carry = 0;
	Node* node1 = list1;
	Node* node2 = list2;
	Node* list = new Node();
	Node* pointer = list;

	while(node1 != nullptr || node2 != nullptr)
	{
		int x = (node1 != nullptr) ? node1->data : 0;
		int y = (node2 != nullptr) ? node2->data : 0;
		int sum = carry + x + y;

		carry = sum / 10;
		pointer->next = new Node(sum % 10);
		pointer = pointer->next;

		if(node1 != nullptr) node1 = node1->next;
		if(node2 != nullptr) node2 = node2->next;
	}

	if(carry > 0)
	{
		pointer->next = new Node(carry);
	}

	return list->next;
}

Node* sum;
Node* pointer;
Node* list1 = new Node();
Node* list2 = new Node();

int main()
{
	int i = 0;
	pointer = list1;
	while(i < 8)
	{
		i++;
		pointer->next = new Node();
		pointer = pointer->next;
	}

	i = 0;
	pointer = list2;
	while(i < 8)
	{
		i++;
		pointer->next = new Node();
		pointer = pointer->next;
	}

	i = 1;
	pointer = list1;
	while(pointer != nullptr)
	{
		pointer->data = i++;
		pointer = pointer->next;
	}

	i = 1;
	pointer = list2;
	while(pointer != nullptr)
	{
		pointer->data = i++;
		pointer = pointer->next;
	}

	sum = AddTwoNumbers(list1, list2);

	pointer = list1;
	while(pointer != nullptr)
	{
		std::cout << pointer->data;
		pointer = pointer->next;
	}

	std::cout << '\n';

	pointer = list2;
	while(pointer != nullptr)
	{
		std::cout << pointer->data;
		pointer = pointer->next;
	}

	std::cout << '\n';

	pointer = sum;
	while(pointer != nullptr)
	{
		std::cout << pointer->data;
		pointer = pointer->next;
	}
}