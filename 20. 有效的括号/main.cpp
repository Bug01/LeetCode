// 20. 有效的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;


//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//示例 1:
//	输入: "()"
//	输出 : true
//
//示例 2 :
//	输入 : "()[]{}"
//	输出 : true
//
//示例 3 :
//	输入 : "(]"
//	输出 : false
//
//示例 4 :
//	输入 : "([)]"
//	输出 : false
//
//示例 5 :
//	输入 : "{[]}"
//	输出 : true



class Solution {
public:
	bool isValid(string s) {

		// 奇数个字符必然不能匹配
		unsigned int leng = s.size();
		if ((leng & 1))
			return false;

		stack<char> sk;
		for (unsigned int i = 0; i < leng; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				sk.push(s[i]);
			else
			{
				// 没有匹配的
				if (sk.empty())
					return false;

				// 取出栈顶元素
				char k = sk.top();

				if ((s[i] == ')' && k == '(') ||
					(s[i] == ']' && k == '[') ||
					(s[i] == '}' && k == '{'))
					sk.pop();
				else
					return false;
			}
		}
		if (sk.empty())
			return true;
		return false;
	}
};

//执行用时:0 ms
//内存消耗 :8.2 MB


int main()
{
	Solution s;

	std::cout << s.isValid("(()(");
}
