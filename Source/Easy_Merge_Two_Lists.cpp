#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Merge_Two_Lists(ListNode* l1, ListNode* l2)
{
	ListNode* node = nullptr;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;

	if(l1 != nullptr && l2 == nullptr) return l1;
	if(l1 == nullptr && l2 != nullptr) return l2;

	while(l1 != nullptr && l2 != nullptr)
	{
		node = (l1->val < l2->val) ? l1 : l2;
		if(tail == nullptr) head = node; else tail->next = node; tail = node;
		if(l1->val < l2->val) l1 = l1->next; else l2 = l2->next;
	}

	if(l1 != nullptr) {tail->next = l1; tail = l1;}
	if(l2 != nullptr) {tail->next = l2; tail = l2;}

	return head;
}

ListNode* l1 = nullptr;
ListNode* l2 = nullptr;

int main()
{
	for(int i = 10; i > 0; i--)
	{
		ListNode* node = new ListNode(i, l1);
		l1 = node;
	}

	for(int i = 10; i > 0; i--)
	{
		ListNode* node = new ListNode(i, l2);
		l2 = node;
	}

	ListNode* list = Merge_Two_Lists(l1, l2);

	while(list != nullptr)
	{
		std::cout << list->val << '\n';
		list = list->next;
	}
}