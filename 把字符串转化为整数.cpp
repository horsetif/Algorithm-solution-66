/*
题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入：
+2147483647
	1a33
输出：
2147483647
	0



思路：首先检测第一位是不是+-号。然后检测剩下的字符。如果出现异常，那么就直接返回。
*/

int StrToInt(string str) {
	int n = str.size(), res = 0;
	//没有数值的情况，或者只有一个符号
	if (n == 0 || (n == 1 && (str[0]<'0' || str[0]>'1'))) return 0;
	bool flag = true;
	int index = 0;//初始索引值
	//检测第一个数值是不是符号位
	if (str[index] == '-') {
		flag = false; index++;
	}
	else if (str[index] == '+') index++;
	while (index < n) {
		//异常处理
		if (str[index] < '0' || str[index] > '9') return 0;
		res = res * 10 + (str[index] - '0');//更新处理
		index++;
	}
	//符号检测
	if (!flag) res = -1 * res;
	return res;
}