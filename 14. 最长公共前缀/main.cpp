// 14. 最长公共前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		string ret(strs[0]);

		for (int i = 1; i < strs.size(); i++) {
			int leng = min(ret.size(), strs[i].size());
			for (int k = leng; k >= 0; k--)
			{
				// 提前结束
				if (k == 0)
					return "";

				if (ret.compare(0, k, strs[i], 0, k) == 0)
				{
					ret.assign(strs[i], 0, k);
					break;
				}
			}
		}
		return ret;
	}
};

//执行用时 :8 ms
//内存消耗 :11.3 MB


int main()
{
	vector<string> tar;
	tar.push_back("dog");
	tar.push_back("flow");
	tar.push_back("flight");

	Solution s;
	string ret = s.longestCommonPrefix(tar);

	std::cout << ret;
}