// 67. 二进制求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。

示例 1:
	输入: a = "11", b = "1"
	输出: "100"

示例 2:
	输入: a = "1010", b = "1011"
	输出: "10101"
 

提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

*/

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {
		string c;
		int carry = 0;
		int sum;

		// 用0补充俩字符串长度相同
		int cn = a.length() - b.length();
		if (cn > 0)
			b.insert(0, cn, '0');
		else if (cn < 0)
			a.insert(0, -cn, '0');

		// 遍历相加
		for (int i = a.length() - 1; i >= 0; i--)
		{
			sum = a[i] - '0' + b[i] - '0' + carry;
			if (sum == 0 || sum == 2)
				c.insert(0, "0");
			else if (sum == 1 || sum == 3)
				c.insert(0, "1");
			carry = sum / 2;
		}

		// 处理进位
		if (carry) {
			c.insert(0, "1");
		}

		return c;
	}
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了100.00%的用户


int main()
{
	string a, b;
	cin >> a;
	cin >> b;

	Solution s;
	string c = s.addBinary(a, b);

	std::cout << c << std::endl;
}



