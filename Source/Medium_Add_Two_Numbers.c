#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* AddTwoNumbers(struct Node* list1, struct Node* list2)
{
	int carry = 0;
	struct Node* node1 = list1;
	struct Node* node2 = list2;
	struct Node* list = malloc(sizeof(struct Node));
	struct Node* pointer = list;

	while(node1 != NULL || node2 != NULL)
	{
		int x = (node1 != NULL) ? node1->data : 0;
		int y = (node2 != NULL) ? node2->data : 0;
		int sum = carry + x + y;

		carry = sum / 10;
		pointer->next = malloc(sizeof(struct Node));
		pointer->next->data = sum % 10;
		pointer = pointer->next;

		if(node1 != NULL) node1 = node1->next;
		if(node2 != NULL) node2 = node2->next;
	}

	if(carry > 0)
	{
		pointer->next = malloc(sizeof(struct Node));
		pointer->next->data = carry;
	}

	return list->next;
}

int main()
{
	struct Node* sum;
	struct Node* pointer;
	struct Node* list1 = malloc(sizeof(struct Node));
	struct Node* list2 = malloc(sizeof(struct Node));

	int i = 0;
	pointer = list1;
	while(i < 8)
	{
		i++;
		pointer->next = malloc(sizeof(struct Node));
		pointer = pointer->next;
	}

	i = 0;
	pointer = list2;
	while(i < 8)
	{
		i++;
		pointer->next = malloc(sizeof(struct Node));
		pointer = pointer->next;
	}

	i = 1;
	pointer = list1;
	while(pointer != NULL)
	{
		pointer->data = i++;
		pointer = pointer->next;
	}

	i = 1;
	pointer = list2;
	while(pointer != NULL)
	{
		pointer->data = i++;
		pointer = pointer->next;
	}

	sum = AddTwoNumbers(list1, list2);

	pointer = list1;
	while(pointer != NULL)
	{
		printf("%d", pointer->data);
		pointer = pointer->next;
	}

	printf("\n");

	pointer = list2;
	while(pointer != NULL)
	{
		printf("%d", pointer->data);
		pointer = pointer->next;
	}

	printf("\n");

	pointer = sum;
	while(pointer != NULL)
	{
		printf("%d", pointer->data);
		pointer = pointer->next;
	}
}