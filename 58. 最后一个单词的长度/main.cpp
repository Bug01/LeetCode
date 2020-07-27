// 58. 最后一个单词的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

示例:
	输入: "Hello World"
	输出: 5

*/

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = s.size();
		int maxLength = 0;

		// 反向遍历查找一个单词
		for (int i = length - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				if (maxLength > 0)
					return maxLength;
			}
			else
				maxLength++;
		}

		return maxLength;
	}
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了100.00%的用户


int main()
{
	Solution s;
	string tar = "Hello World";

    std::cout << s.lengthOfLastWord(tar);;
}

