// 101. 对称二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
 给定一个二叉树，检查它是否是镜像对称的。

 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

	1
   / \
  2   2
 / \ / \
3  4 4  3

 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

	1
   / \
  2   2
   \   \
   3    3

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define EmptyNode -1


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;

		return isEqual(leftNode, rightNode);
	}

	bool isEqual(TreeNode* l, TreeNode* r)
	{
		if (l == NULL && r == NULL)
			return true;
		if (l == NULL || r == NULL)
			return false;
		if (l->val != r->val)
			return false;
		

		// 递归比较
		if (isEqual(l->left, r->right) &&
			isEqual(l->right, r->left))
			return true;
		
		return false;
	}
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了47.31%的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了74.93%的用户

int main()
{
	vector<int32_t> k = { 1, 2, 2, EmptyNode, 3, EmptyNode, 3 };
	//vector<int32_t> k = { 1, 2, 2, 3, 4, 4, 3 };

	queue<TreeNode*> treeQueue;
	TreeNode *tree = nullptr;
	
	// 初始化root节点
	int index = 0;
	if (k[index] != EmptyNode)
	{
		TreeNode* tmp = new TreeNode(k[index]);
		treeQueue.push(tmp);
		
		tree = tmp;
		index++;
	}

	// 初始化数
	while (!treeQueue.empty() && index < k.size())
	{
		// 删除节点
		TreeNode* t = treeQueue.front();
		treeQueue.pop();

		// 生成左子节点
		if ((k[index]) != EmptyNode)
		{
			TreeNode* tL = new TreeNode(k[index]);
			t->left = tL;
			treeQueue.push(tL);
		}
		index++;

		// 生成右子节点
		if ((k[index]) != EmptyNode)
		{
			TreeNode* tR = new TreeNode(k[index]);
			t->right = tR;
			treeQueue.push(tR);
		}
		index++;
	}

	Solution s;
    std::cout << s.isSymmetric(tree);
}
