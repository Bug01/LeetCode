// 88. 合并两个有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。
//	说明 :
//	初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//	你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//
// 示例 :
// 输入:
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
// 输出 : [1, 2, 2, 3, 5, 6]


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = m - 1;
		int p2 = n - 1;
		int p = m + n - 1;

		while (p1 >= 0 && p2 >= 0)
		{
			if (nums1[p1] > nums2[p2])
				nums1[p--] = nums1[p1--];
			else
				nums1[p--] = nums2[p2--];
		}

		// nums2还有数据
		while (p2 >= 0)
		{
			nums1[p--] = nums2[p2--];
		}
	}
};

//执行用时:0 ms
//内存消耗 :6.6 MB



int main()
{
	vector<int> nums1;
	vector<int> nums2;

	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);


	nums2.push_back(2);
	nums2.push_back(5);
	nums2.push_back(6);

	Solution s;
	s.merge(nums1, 3, nums2, 3);


	std::cout << "Hello World!\n";
}
