// 3. 无重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1 :
//	输入: "abcabcbb"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
//示例 2 :
//	输入 : "bbbbb"
//	输出 : 1
//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//	
//示例 3 :
//	输入 : "pwwkew"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;

		int start = 0;
		int end = 0;
		int maxLeng = 1;
		int curLeng = 0;

		while (s[end] && s[end + 1])
		{
			string k = s.substr(start, end + 1 - start);
			int pos = k.find(s[end + 1]);
			curLeng = k.size();

			if (pos == string::npos)
			{
				end += 1;
				if (curLeng + 1 > maxLeng)
					maxLeng = curLeng + 1;
			}
			else
			{
				// 移动开始位置
				start = start + pos + 1;
				end = start;

				// 更新最大长度

				if (curLeng > maxLeng)
					maxLeng = curLeng;
			}
		}
		return maxLeng;
	}
};

//执行用时:704 ms
//内存消耗 :274.9 MB


int main()
{
	string str("");
	Solution s;


	std::cout << s.lengthOfLongestSubstring(str);
}
