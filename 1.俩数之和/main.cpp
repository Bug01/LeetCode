// 1.俩数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<map>
using namespace std;


//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例 :
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]


// 方法1：暴力遍历法 O(n^2)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (target == nums[i] + nums[j]) {
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		return ret;
	}
};
//方法1：
//执行用时:180 ms
//内存消耗 :11.5 MB


// 方法2：使用哈希表使遍历 O(n)
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		map<int, int> mapTmp;
		for (int i = 0; i < nums.size(); i++) {
			int k = target - nums[i];

			map<int, int>::iterator it_find = mapTmp.find(k);
			if (it_find != mapTmp.end()) {
				ret.push_back(i);
				ret.push_back(it_find->second);
				return ret;
			}
			mapTmp[nums[i]] = i;
		}
		return ret;
	}
};
//方法2：
//执行用时:8 ms
//内存消耗 :12.2 MB




int main()
{
	int a[4] = { 2, 7, 11, 15 };
	int tar = 9;
	vector<int> b;
	vector<int> ret;

	for (int i = 0; i < 4; ++i)
	{
		b.push_back(a[i]);
	}

	Solution2 s;
	ret = s.twoSum(b, tar);

	if (ret.size() == 2) {
		std::cout << ret[0] << "," << ret[1];
	}
	else {
		std::cout << "no";
	}
}


