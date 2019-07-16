/*
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。



思路：以两个数的异或作为基底，以两个数的与*2 作为进位。
迭代计算，直到没有进位为止。

*/

int Add(int num1, int num2) {
	int base = 0, carry = 0;
	do {
		base = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = base; num2 = carry;
	} while (num2 != 0);
	return base;
}