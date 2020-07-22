// 66. 加一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
// 示例 1 :
//	输入: [1, 2, 3]
//	输出 : [1, 2, 4]
//	解释 : 输入数组表示数字 123。
//
// 示例 2 :
//	输入: [4, 3, 2, 1]
//	输出 : [4, 3, 2, 2]
//	解释 : 输入数组表示数字 4321。


class Solution1 {
public:
	vector<int> plusOne(vector<int>& digits) {
		unsigned int end = digits.size() - 1;
		// 不存在进位情况
		if (digits[end] != 9)
			digits[end] += 1;
		else
		{
			bool add = true;
			for (int i = end; i >= 0 && add; i--) {
				// 进位
				if (add && digits[i] == 9) {
					digits[i] = 0;
					add = true;
				}
				// 终止进位
				else
				{
					digits[i] += 1;
					add = false;
				}
			}
			// 最后的进位
			if (add)
				digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

//执行用时:4 ms
//内存消耗 :7.8 MB


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			digits[i] += 1;

			// 进位
			if (digits[i] == 10)
				digits[i] = 0;
			// 终止进位
			else
				return digits;
		}
		// 最后的进位
		digits.insert(digits.begin(), 1);
		return digits;
	}

};

//执行用时:0 ms
//内存消耗 :8.1 MB


int main()
{
	Solution s;
	vector<int> b;
	vector<int> ret;

	b.push_back(9);
	b.push_back(9);
	b.push_back(9);

	ret = s.plusOne(b);

	std::cout << "Hello World!\n";
}

