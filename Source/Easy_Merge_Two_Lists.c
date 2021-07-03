#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* Merge_Two_Lists_Iterative(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* node = NULL;
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	if(l1 != NULL && l2 == NULL) return l1;
	if(l1 == NULL && l2 != NULL) return l2;

	while(l1 != NULL && l2 != NULL)
	{
		node = (l1->val < l2->val) ? l1 : l2;
		if(tail == NULL) head = node; else tail->next = node; tail = node;
		if(l1->val < l2->val) l1 = l1->next; else l2 = l2->next;
	}

	if(l1 != NULL) {tail->next = l1; tail = l1;}
	if(l2 != NULL) {tail->next = l2; tail = l2;}

	return head;
}

struct ListNode* Merge_Two_Lists_Recursive(struct ListNode* l1, struct ListNode* l2)
{
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	if(l1->val < l2->val) {l1->next = Merge_Two_Lists_Recursive(l1->next, l2); return l1;}
	if(l1->val >= l2->val) {l2->next = Merge_Two_Lists_Recursive(l1, l2->next); return l2;}
	return NULL;
}

struct ListNode* l1 = NULL;
struct ListNode* l2 = NULL;

int main()
{
	for(int i = 10; i > 0; i--)
	{
		struct ListNode* node = malloc(sizeof(struct ListNode));
		node->val = i;
		node->next = l1;
		l1 = node;
	}

	for(int i = 10; i > 0; i--)
	{
		struct ListNode* node = malloc(sizeof(struct ListNode));
		node->val = i;
		node->next = l2;
		l2 = node;
	}

	struct ListNode* list = Merge_Two_Lists_Iterative(l1, l2);

	while(list != NULL)
	{
		printf("%d\n", list->val);
		list = list->next;
	}
}