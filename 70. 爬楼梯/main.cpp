// 70. 爬楼梯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
using namespace std;


//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//注意：给定 n 是一个正整数。
//
// 示例 1：
//	输入： 2
//	输出： 2
//	解释： 有两种方法可以爬到楼顶。
//		1.  1 阶 + 1 阶
//		2.  2 阶
//
// 示例 2：
//	输入： 3
//	输出： 3
//	解释： 有三种方法可以爬到楼顶。
//		1.  1 阶 + 1 阶 + 1 阶
//		2.  1 阶 + 2 阶
//		3.  2 阶 + 1 阶



class Solution {
public:
	map<int, int> history;

	int climbStairs(int n) {
		// 检查是否已经计算过了
		map<int, int>::iterator iter = this->history.find(n);
		if (iter != this->history.end())
			return iter->second;

		// 递归终止
		if (n == 0 || n == 1)
			return 1;

		// 保存计算的结果
		unsigned int ret = climbStairs(n - 1) + climbStairs(n - 2);
		this->history[n] = ret;

		return ret;
	}
};
//执行用时:4 ms
//内存消耗 :8.9 MB

// 【注意】
// 如果写成下面的情况 当n的值较大时，出现递归超时，
// 所以必须对已经计算过的数据进行保存再使用

/*
	int climbStairs(int n) {
		if (n == 0 || n == 1)
			return 1;
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
*/


int main()
{
	Solution s;

	std::cout << s.climbStairs(44);
}

