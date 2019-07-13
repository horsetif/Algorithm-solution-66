/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。


思路：首先整体框架是如果次方数是2的倍数，a^(2*n) =  (a^n) * (a^n) . or  a^(2*n+1) = a^n * a^n * a
接下来要考虑如果a是负数的情况，已经n是负数的情况。

*/
double Power(double base, int exponent) {
	//基础设置
	if (base == 0) return 0;
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	bool base_flag = false, exponent_flag = false;
	//针对负数的设置
	if (base < 0) {
		base_flag = true;
		base = -1 * base;
	}
	if (exponent < 0) {
		exponent_flag = true;
		exponent = -1 * exponent;
	}
	//下面应该都是正数计算了
	double res = Power(base, exponent / 2);
	if (exponent % 2 == 0) res = res * res;
	else res = res * res * base;
	//如果本来底数就是负数，且指数是奇数，那么输出应该是负数
	if (base_flag && exponent % 2 != 0) res = -1 * res;
	//如果本来指数是负数，那么输出应该是导数
	if (exponent_flag) res = 1 / res;
	return res;
}
