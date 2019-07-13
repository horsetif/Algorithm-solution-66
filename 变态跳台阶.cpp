/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。



思路：f(1) = f(0)
	  f(2) = f(1) + f(0) (挑一格，剩下f(1)。跳两格，剩下f(0)) 
	  f(3) = f(2) + f(1) + f(0)
	  f(4) = f(3) + f(2) + f(1) + f(0)
	  f(n) = 2 * f(n-1) 且 f(1) = 1, f(0) = 1
*/

int jumpFloorII(int number) {
	int res = 1;
	if (number == 1) return res;//如果是1格子，那么就直接返回
	number--;//否则后面都累积乘二就好
	while (number-- > 0) res = res * 2;
	return res;
}