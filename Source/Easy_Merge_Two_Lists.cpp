#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int x) : data(x), next(nullptr) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

Node* MergeTwoListsIterative(Node* list1, Node* list2)
{
	Node* node = nullptr;
	Node* head = nullptr;
	Node* tail = nullptr;

	if(list1 != nullptr && list2 == nullptr) return list1;
	if(list1 == nullptr && list2 != nullptr) return list2;

	while(list1 != nullptr && list2 != nullptr)
	{
		node = (list1->data < list2->data) ? list1 : list2;
		if(tail == nullptr) head = node; else tail->next = node; tail = node;
		if(list1->data < list2->data) list1 = list1->next; else list2 = list2->next;
	}

	if(list1 != nullptr) {tail->next = list1; tail = list1;}
	if(list2 != nullptr) {tail->next = list2; tail = list2;}

	return head;
}

Node* MergeTwoListsRecursive(Node* list1, Node* list2)
{
	if(list1 == nullptr) return list2;
	if(list2 == nullptr) return list1;
	if(list1->data < list2->data) {list1->next = MergeTwoListsRecursive(list1->next, list2); return list1;}
	if(list1->data >= list2->data) {list2->next = MergeTwoListsRecursive(list1, list2->next); return list2;}
	return nullptr;
}

Node* list1 = nullptr;
Node* list2 = nullptr;

int main()
{
	for(int i = 10; i > 0; i--)
	{
		Node* node = new Node(i, list1);
		list1 = node;
	}

	for(int i = 10; i > 0; i--)
	{
		Node* node = new Node(i, list2);
		list2 = node;
	}

	Node* list = MergeTwoListsIterative(list1, list2);

	while(list != nullptr)
	{
		std::cout << list->data << '\n';
		list = list->next;
	}
}