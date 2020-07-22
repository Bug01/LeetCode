// 69. x 的平方根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


//实现 int sqrt(int x) 函数。
//计算并返回 x 的平方根，其中 x 是非负整数。
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//
// 示例 1:
//	输入: 4
//	输出 : 2
//
// 示例 2 :
//	输入 : 8
//	输出 : 2
//	说明 : 8 的平方根是 2.82842...,
	//由于返回类型是整数，小数部分将被舍去。



// 二分法
class Solution {
public:
	int mySqrt(int x) {
		if (x < 2)
			return x;

		long low = 0;
		long high = x / 2;

		while (low <= high)
		{
			long long mid = (low + high) / 2;

			if (mid * mid == x)
				return mid;
			else if (mid * mid < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return low - 1;
	}
};
//执行用时 :4 ms
//内存消耗 :6 MB

// 最佳方法是牛顿迭代法

int main()
{
	Solution s;

	//for (int i = 0; i < 20; i++)
	//	cout << i << ": " << s.mySqrt(i) << endl;

	cout << s.mySqrt(2147395599);
}

