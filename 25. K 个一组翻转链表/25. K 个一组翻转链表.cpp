// 25. K 个一组翻转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
	给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
	k 是一个正整数，它的值小于或等于链表的长度。
	如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 
示例：
	给你这个链表：1->2->3->4->5

	当 k = 2 时，应当返回: 2->1->4->3->5
	当 k = 3 时，应当返回: 3->2->1->4->5
*/

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* p = head;
		ListNode* cur = head;
		vector<int> valList;

		while (cur)
		{
			// 保存当前位置
			valList.push_back(cur->val);
			cur = cur->next;

			// 开始反转
			if (valList.size() == k)
			{
				for (int i = valList.size() - 1; i >= 0; i--)
				{
					p->val = valList[i];
					p = p->next;
				}
				valList.clear();
			}
		}
		return head;
	}
};

// 执行用时：28 ms, 在所有 C++ 提交中击败了59.97%的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了37.08%的用户


int main()
{
	// 初始化链表
	ListNode* list = NULL;
	ListNode* p = NULL;
	vector<int> k = { 1,2,3,4,5 };

	for (int i = 0; i < k.size(); i++)
	{
		ListNode* t = new ListNode(k[i]);

		if (list == NULL)
		{
			list = t;
			p = t;
		}
		else
		{
			p->next = t;
			p = t;
		}
	}

	// 链表反转
	Solution s;
	ListNode* ret = s.reverseKGroup(list, 2);

	// 输出结果
	while (ret)
	{
		std::cout << ret->val << ",";

		ListNode* p = ret;
		ret = ret->next;
		delete p;
	}
}
