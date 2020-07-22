// 26. 删除排序数组中的重复项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//
//示例 1 :
//	给定数组 nums = [1, 1, 2],
//	函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//	你不需要考虑数组中超出新长度后面的元素。
//
//示例 2 :
//	给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//	函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//	你不需要考虑数组中超出新长度后面的元素。


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		unsigned int slow = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[slow] != nums[i])
			{
				slow++;

				// 检查是否需要赋值
				if (slow != i)
					nums[slow] = nums[i];
			}
		}
		return slow + 1;
	}
};

//执行用时:12 ms
//内存消耗 :14.4 MB


int main()
{
	vector<int> v = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

	Solution s;
	int t = s.removeDuplicates(v);
	cout << t << endl;

	for (int i = 0; i < t; i++)
		std::cout << v[i] << " ";
}
