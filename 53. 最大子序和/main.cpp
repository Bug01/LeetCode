// 53. 最大子序和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:

	输入: [-2,1,-3,4,-1,2,1,-5,4]
	输出: 6
	解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
	如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSub = nums[0];
		int curSub = nums[0];
		int tmp = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			tmp = curSub + nums[i];

			// 如果该节点的值比与前面连续数组的值要大
			// 抛弃前面的值 从该节点重新开始
			if (nums[i] > tmp)
				curSub = nums[i];
			else
				curSub = tmp;

			if (curSub > maxSub)
				maxSub = curSub;
		}

		return maxSub;
	}
};

//执行用时：4 ms, 在所有 C++ 提交中击败了97.40%的用户
//内存消耗：6.9 MB, 在所有 C++ 提交中击败了100.00%的用户


int main()
{
	vector<int> tar = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	Solution s;
    std::cout << s.maxSubArray(tar);
}

