// 21. 合并两个有序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* top = head;

		while (l1 && l2)
		{
			if (l1->val <= l2->val) {
				top->next = l1;
				l1 = l1->next;
			}
			else {
				top->next = l2;
				l2 = l2->next;
			}
			top = top->next;
		}
		if (l1)
			top->next = l1;
		if (l2)
			top->next = l2;

		ListNode* t = head;
		head = head->next;
		delete t;
		return head;
	}
};


//执行用时 :8 ms
//内存消耗 :15.9 MB

int main()
{
	ListNode* l1 = &ListNode(1);
	ListNode* l2 = &ListNode(1);
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* ret = NULL;
	Solution s;


	ListNode node1(2);
	p1->next = &node1;
	p1 = p1->next;

	ListNode node2(4);
	p1->next = &node2;
	p1 = p1->next;

	ListNode node3(3);
	p2->next = &node3;
	p2 = p2->next;

	ListNode node4(4);
	p2->next = &node4;
	p2 = p2->next;

	ret = s.mergeTwoLists(l1, l2);

	std::cout << "Hello World!\n";
}
