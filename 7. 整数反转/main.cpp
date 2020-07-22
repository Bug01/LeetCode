// 7. 整数反转.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//
//示例 1 :
//	输入: 123
//	输出 : 321
//
//示例 2 :
//	输入 : -123
//	输出 : -321
//
//示例 3 :
//	输入 : 120
//	输出 : 21


class Solution1 {
public:
	int reverse(int x) {
		int ret = 0;

		while (x)
		{
			int k = x % 10;

			// 溢出判断
			if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && k > 7))
				return 0;
			if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && k < -8))
				return 0;

			ret = ret * 10 + k;
			x = x / 10;
		}
		return ret;
	}
};

//执行用时 :8 ms
//内存消耗 :8.1 MB


class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		int max = INT_MAX / 10;
		int min = INT_MIN / 10;

		while (x)
		{
			int k = x % 10;

			// 溢出判断
			if (ret > max || (ret == max && k > 7))
				return 0;
			if (ret < min || (ret == min && k < -8))
				return 0;

			ret = ret * 10 + k;
			x = x / 10;
		}
		return ret;
	}
};

//执行用时:0 ms，把阈值计算放到循环外 优化计算速度
//内存消耗 :8.2 MB




int main()
{
	Solution s;
	int x = -123;

	std::cout << s.reverse(x);
}