#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* MergeTwoListsIterative(struct Node* list1, struct Node* list2)
{
	struct Node* node = NULL;
	struct Node* head = NULL;
	struct Node* tail = NULL;

	if(list1 != NULL && list2 == NULL) return list1;
	if(list1 == NULL && list2 != NULL) return list2;

	while(list1 != NULL && list2 != NULL)
	{
		node = (list1->data < list2->data) ? list1 : list2;
		if(tail == NULL) head = node; else tail->next = node; tail = node;
		if(list1->data < list2->data) list1 = list1->next; else list2 = list2->next;
	}

	if(list1 != NULL) {tail->next = list1; tail = list1;}
	if(list2 != NULL) {tail->next = list2; tail = list2;}

	return head;
}

struct Node* MergeTwoListsRecursive(struct Node* list1, struct Node* list2)
{
	if(list1 == NULL) return list2;
	if(list2 == NULL) return list1;
	if(list1->data < list2->data) {list1->next = MergeTwoListsRecursive(list1->next, list2); return list1;}
	if(list1->data >= list2->data) {list2->next = MergeTwoListsRecursive(list1, list2->next); return list2;}
	return NULL;
}

struct Node* list1 = NULL;
struct Node* list2 = NULL;

int main()
{
	for(int i = 10; i > 0; i--)
	{
		struct Node* node = malloc(sizeof(struct Node));
		node->data = i;
		node->next = list1;
		list1 = node;
	}

	for(int i = 10; i > 0; i--)
	{
		struct Node* node = malloc(sizeof(struct Node));
		node->data = i;
		node->next = list2;
		list2 = node;
	}

	struct Node* list = MergeTwoListsIterative(list1, list2);

	while(list != NULL)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
}