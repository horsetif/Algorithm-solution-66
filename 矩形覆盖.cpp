/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？


思路：f(1) = 1 （竖着）
	  f(2) = 2 (两竖两横）
	  f(3) = f(1) + f(2)
	  f(4) = f(3) + f(2) (只看头两个）
	  说明还是斐波那契数列的问题。
*/

int rectCover(int number) {
	int step1 = 0, step2 = 1;//初始状态
	int res;
	if (number <= 0) return 0;
	while (number-- > 0) {
		res = step1 + step2;//更新结果
		step1 = step2;
		step2 = res;
	}
	return res;
}