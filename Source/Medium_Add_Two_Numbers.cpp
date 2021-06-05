#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Add_Two_Numbers(ListNode* l1, ListNode* l2)
{
	int carry = 0;
    ListNode* node1 = l1;
    ListNode* node2 = l2;
    ListNode* sumList = new ListNode();
    ListNode* current = sumList;

    while(node1 != nullptr || node2 != nullptr)
	{
        int x = (node1 != nullptr) ? node1->val : 0;
        int y = (node2 != nullptr) ? node2->val : 0;
        int sum = carry + x + y;

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;

        if(node1 != nullptr) node1 = node1->next;
        if(node2 != nullptr) node2 = node2->next;
    }

    if(carry > 0)
	{
        current->next = new ListNode(carry);
    }

    return sumList->next;
}

ListNode* ptr;
ListNode* sum;
ListNode* l1 = new ListNode();
ListNode* l2 = new ListNode();

int main()
{
	ptr = l1;
	int i = 0;
	while(i < 8)
	{
		i++;
		ptr->next = new ListNode();
		ptr = ptr->next;
	}

	i = 0;
	ptr = l2;
	while(i < 8)
	{
		i++;
		ptr->next = new ListNode();
		ptr = ptr->next;
	}

	i = 1;
	ptr = l1;
	while(ptr != nullptr)
	{
		ptr->val = i++;
		ptr = ptr->next;
	}

	i = 1;
	ptr = l2;
	while(ptr != nullptr)
	{
		ptr->val = i++;
		ptr = ptr->next;
	}

	sum = Add_Two_Numbers(l1, l2);

	ptr = l1;
	while(ptr != nullptr)
	{
		std::cout << ptr->val;
		ptr = ptr->next;
	}

	std::cout << '\n';

	ptr = l2;
	while(ptr != nullptr)
	{
		std::cout << ptr->val;
		ptr = ptr->next;
	}

	std::cout << '\n';

	ptr = sum;
	while(ptr != nullptr)
	{
		std::cout << ptr->val;
		ptr = ptr->next;
	}
}