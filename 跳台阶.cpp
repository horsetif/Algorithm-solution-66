/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。


思路：很明显是斐波那契数列，这里没有具体的n值，所有最好不要新建数组做。
*/
int jumpFloor(int number) {
	int step1 = 0, step2 = 1;//记录前两个台阶的值
	int res = 1;//当前值
	while (number-- > 0) {
		res = step1 + step2;
		step1 = step2;
		step2 = res;
	}
	return res;
}
