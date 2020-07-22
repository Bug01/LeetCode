// 35. 搜索插入位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
// 示例 1:
//	输入: [1, 3, 5, 6], 5
//	输出 : 2
//	
// 示例 2 :
//	输入 : [1, 3, 5, 6], 2
//	输出 : 1
//
// 示例 3 :
//	输入 : [1, 3, 5, 6], 7
//	输出 : 4
//
// 示例 4 :
//	输入 : [1, 3, 5, 6], 0
//	输出 : 0


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		unsigned int low = 0;
		unsigned int high = nums.size() - 1;

		// 最大最小的情况
		if (target <= nums[low])
			return low;
		if (target == nums[high])
			return high;
		if (target > nums[high])
			return high + 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < target)
				low = mid + 1;
			if (nums[mid] > target)
				high = mid - 1;
		}
		return low;
	}
};

//执行用时:4 ms
//内存消耗 :11.1 MB

int main()
{
	vector<int> nums = { 1, 3, 5, 6 };
	int tar = 2;

	Solution s;
	std::cout << s.searchInsert(nums, tar);
}

