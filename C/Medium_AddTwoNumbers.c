#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* AddTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0;
    struct ListNode* node1 = l1;
    struct ListNode* node2 = l2;
    struct ListNode* sumList = malloc(sizeof(struct ListNode));
    struct ListNode* current = sumList;

    while(node1 != NULL || node2 != NULL)
	{
        int x = (node1 != NULL) ? node1->val : 0;
        int y = (node2 != NULL) ? node2->val : 0;
        int sum = carry + x + y;

        carry = sum / 10;
        current->next = malloc(sizeof(struct ListNode));
        current->next->val = sum % 10;
        current = current->next;

        if(node1 != NULL) node1 = node1->next;
        if(node2 != NULL) node2 = node2->next;
    }

    if(carry > 0)
	{
        current->next = malloc(sizeof(struct ListNode));
        current->next->val = carry;
    }

    return sumList->next;
}

int main()
{
	struct ListNode* ptr;
	struct ListNode* sum;
	struct ListNode* l1 = malloc(sizeof(struct ListNode));
	struct ListNode* l2 = malloc(sizeof(struct ListNode));

	ptr = l1;
	int i = 0;
	while(i < 8)
	{
		i++;
		ptr->next = malloc(sizeof(struct ListNode));
		ptr = ptr->next;
	}

	i = 0;
	ptr = l2;
	while(i < 8)
	{
		i++;
		ptr->next = malloc(sizeof(struct ListNode));
		ptr = ptr->next;
	}

	i = 1;
	ptr = l1;
	while(ptr != NULL)
	{
		ptr->val = i++;
		ptr = ptr->next;
	}

	i = 1;
	ptr = l2;
	while(ptr != NULL)
	{
		ptr->val = i++;
		ptr = ptr->next;
	}

	sum = AddTwoNumbers(l1, l2);

	ptr = l1;
	while(ptr != NULL)
	{
		printf("%d", ptr->val);
		ptr = ptr->next;
	}

	printf("\n");

	ptr = l2;
	while(ptr != NULL)
	{
		printf("%d", ptr->val);
		ptr = ptr->next;
	}

	printf("\n");

	ptr = sum;
	while(ptr != NULL)
	{
		printf("%d", ptr->val);
		ptr = ptr->next;
	}
}