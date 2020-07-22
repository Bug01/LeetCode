// 2. 两数相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 方法1
class Solution1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL;
		ListNode* l = head;
		int carry = 0;

		while (l1 != NULL && l2 != NULL)
		{
			// 增加新节点
			int k = l1->val + l2->val + carry;
			ListNode* node = new ListNode(k % 10);
			if (head == NULL)
			{
				head = node;
				l = node;
			}
			else
			{
				l->next = node;
				l = l->next;
			}


			// 处理其他
			carry = k > 9 ? 1 : 0;

			l1 = l1->next;
			l2 = l2->next;
		}

		// 处理一个结束一个未结束的情况
		ListNode* p = NULL;
		if (l1 != NULL)
			p = l1;
		else if (l2 != NULL)
			p = l2;
		while (p != NULL)
		{
			// 增加新节点
			int k = p->val + carry;
			ListNode* node = new ListNode(k % 10);
			l->next = node;

			// 处理其他
			carry = k > 9 ? 1 : 0;
			l = l->next;
			p = p->next;
		}

		// 俩个链表都结束 但是有进位
		if (carry)
		{
			ListNode* node = new ListNode(carry);
			l->next = node;
		}

		return head;
	}
};

//执行用时:32 ms
//内存消耗:72.4 MB


// 方法2
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL;
		ListNode* l = head;
		int carry = 0;

		while (l1 != NULL || l2 != NULL || carry)
		{
			int k = carry;
			if (l1)
			{
				k += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				k += l2->val;
				l2 = l2->next;
			}

			// 增加新节点
			ListNode* node = new ListNode(k % 10);
			if (head == NULL)
			{
				head = node;
				l = node;
			}
			else
			{
				l->next = node;
				l = l->next;
			}

			// 进位处理
			carry = k > 9 ? 1 : 0;
		}

		return head;
	}
};

//执行用时:40 ms
//内存消耗 :72.4 MB

int main()
{
	ListNode* l1 = &ListNode(2);
	ListNode* l2 = &ListNode(5);
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* ret = NULL;
	Solution s;


	ListNode node1(4);
	p1->next = &node1;
	p1 = p1->next;

	ListNode node2(3);
	p1->next = &node2;
	p1 = p1->next;

	ListNode node3(6);
	p2->next = &node3;
	p2 = p2->next;

	ListNode node4(4);
	p2->next = &node4;
	p2 = p2->next;

	ret = s.addTwoNumbers(l1, l2);
}

