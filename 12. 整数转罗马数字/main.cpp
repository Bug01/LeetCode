// 12. 整数转罗马数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:
	输入: 3
	输出: "III"

示例 2:
	输入: 4
	输出: "IV"

示例 3:
	输入: 9
	输出: "IX"

示例 4:
	输入: 58
	输出: "LVIII"
	解释: L = 50, V = 5, III = 3.

示例 5:
	输入: 1994
	输出: "MCMXCIV"
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


class Solution {
public:
	string intToRoman1(int num) 
	{
		string ret;
		vector<pair<int, string>> dict = { make_pair(1, "I"), make_pair(4, "IV"), make_pair(5,"V"), make_pair(9,"IX"),
											make_pair(10,"X"), make_pair(40,"XL"), make_pair(50,"L"), make_pair(90,"XC"),
											make_pair(100,"C"), make_pair(400,"CD"), make_pair(500,"D"), make_pair(900,"CM"),
											make_pair(1000,"M") };
		
		
		// 从大到小遍历字典值
		for (vector<pair<int, string>>::reverse_iterator item = dict.rbegin(); item != dict.rend(); item++)
		{
			// 如果当前值比字典值要大 则转换
			while (num >= (*item).first)
			{
				ret += (*item).second;

				num -= (*item).first;
			}
		}
		return ret;

		//执行用时：32 ms, 在所有 C++ 提交中击败了18.28%的用户
		//内存消耗：9.8 MB, 在所有 C++ 提交中击败了14.87%的用户
	}
	

	string intToRoman2(int num)
	{
		string ret;
		vector<pair<int, string>> dict = { make_pair(1000,"M"), make_pair(900,"CM"), make_pair(500,"D"), make_pair(400,"CD"),
											make_pair(100,"C"), make_pair(90,"XC"), make_pair(50,"L"), make_pair(40,"XL"),
											make_pair(10,"X"), make_pair(9,"IX"), make_pair(5,"V"), make_pair(4, "IV"), make_pair(1, "I") };


		// 从大到小遍历字典值
		for (vector<pair<int, string>>::iterator item = dict.begin(); item != dict.end(); item++)
		{
			// 如果当前值比字典值要大 则转换
			while (num >= (*item).first)
			{
				ret += (*item).second;

				num -= (*item).first;
			}
		}
		return ret;
	
		//执行用时：20 ms, 在所有 C++ 提交中击败了42.56%的用户
		//内存消耗：9.6 MB, 在所有 C++ 提交中击败了16.67%的用户
	}

	string intToRoman3(int num)
	{
		string ret;
		int tmp = 0;
		vector<int> key = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> val = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };


		// 从大到小遍历字典值
		for (int i = 0; i < key.size(); i++)
		{
			tmp = num / key[i];
			for (int j = 0; j < tmp; j++)
			{
				ret.append(val[i]);
				num -= key[i];
			}
		}
		return ret;

		//执行用时：20 ms, 在所有 C++ 提交中击败了42.56%的用户
		//内存消耗：9.6 MB, 在所有 C++ 提交中击败了16.67%的用户
	}


	string intToRoman(int num)
	{
		string ret;
		map<int, string> dict = { {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1, "I"} };

		int tmpNum = 0;
		int mult = 1;
		while (num > 0)
		{
			tmpNum = num % 10;
			if (dict.count(tmpNum * mult) > 0) // 4, 5, 9
			{
				ret.insert(0, dict[tmpNum * mult]);
			}
			else if (tmpNum < 5) // 1,2,3
			{
				ret.insert(0, tmpNum, dict[mult][0]);
			}
			else if (tmpNum < 9) // 6,7,8
			{
				ret.insert(0, tmpNum - 5, dict[mult][0]);
				ret.insert(0, dict[5 * mult]);

			}

			num /= 10;
			mult *= 10;
		}

		return ret;

		//执行用时：48 ms, 在所有 C++ 提交中击败了10.70%的用户
		//内存消耗：13.2 MB, 在所有 C++ 提交中击败了7.95%的用户
	}
};


int main()
{
	Solution s;
	
	for (int i = 1; i < 11; i++)
	{
		std::cout << i << ":" << s.intToRoman(i) << std::endl;
	}

	std::cout <<  s.intToRoman(3999) << std::endl;
}
