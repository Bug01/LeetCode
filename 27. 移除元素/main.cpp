// 27. 移除元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//示例 1:
//	给定 nums = [3, 2, 2, 3], val = 3,
//	函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//	你不需要考虑数组中超出新长度后面的元素。
//
//示例 2 :
//	给定 nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2,
//	函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
//	注意这五个元素可为任意顺序。
//	你不需要考虑数组中超出新长度后面的元素。。


class Solution1 {
public:
	int removeElement(vector<int>& nums, int val) {
		unsigned int slow = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val)
				nums[slow++] = nums[i];
		}
		return slow;
	}
};
// 代码简洁 丢失数组原有元素
//执行用时 :4 ms
//内存消耗 :10.2 MB


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		unsigned int end = nums.size();
		unsigned int start = 0;
		while (start < end) {
			if (nums[start] == val) {
				nums[start] = nums[end - 1];
				end--;
			}
			else
				start++;
		}
		return end;
	}
};
// 代码简洁 丢失数组原有元素
//执行用时 :4 ms
//内存消耗 :10.2 MB

int main()
{
	vector<int> v = { 3, 2, 2, 3 };
	int val = 3;

	Solution s;
	int t = s.removeElement(v, val);
	cout << t << endl;

	for (int i = 0; i < t; i++)
		std::cout << v[i] << " ";
}

