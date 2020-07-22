// 83. 删除排序链表中的重复元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1 :
//	输入: 1->1->2
//	输出 : 1->2
//
//示例 2 :
//	输入 : 1->1->2->3->3
//	输出 : 1->2->3
//

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* slow = head;
		ListNode* quick = head->next;
		while (quick)
		{
			// 删除相同元素
			if (slow->val == quick->val) {
				slow->next = NULL;

				ListNode* t = quick;
				quick = quick->next;

				//t->next = NULL;
				delete t;
			}
			else {
				slow->next = quick;
				slow = quick;
				quick = quick->next;
			}
		}
		return head;
	}
};

//执行用时:12 ms
//内存消耗 :12.4 MB


int main()
{
	ListNode* ret = NULL;
	Solution s;

	ListNode* l1 = new ListNode(1);
	ListNode* p1 = l1;

	ListNode* node1 = new ListNode(1);
	p1->next = node1;
	p1 = p1->next;

	ListNode* node2 = new ListNode(2);
	p1->next = node2;
	p1 = p1->next;

	ListNode* node3 = new ListNode(3);
	p1->next = node3;
	p1 = p1->next;

	ListNode* node4 = new ListNode(3);
	p1->next = node4;
	p1 = p1->next;

	ret = s.deleteDuplicates(l1);

	std::cout << "Hello World!\n";
}

