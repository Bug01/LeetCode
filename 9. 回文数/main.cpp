// 9. 回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

//示例 1:
//	输入: 121
//	输出 : true
//
//示例 2 :
//	输入 : -121
//	输出 : false
//	解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
//
//示例 3 :
//	输入 : 10
//	输出 : false
//	解释 : 从右向左读, 为 01 。因此它不是一个回文数。



class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		long long ret = 0;
		int t = x;
		while (t)
		{
			int k = t % 10;
			ret = ret * 10 + k;
			t = t / 10;
		}
		if (x == ret)
			return true;
		return false;
	}
};

//执行用时:8 ms
//内存消耗 :8.1 MB


int main()
{
	Solution s;
	bool b = s.isPalindrome(2147483647);

	std::cout << b;
}
