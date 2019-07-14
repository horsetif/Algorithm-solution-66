/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。



思路：分步翻转。先分别翻转一次，然后再总体翻转一次。
1，分别翻转： cba fedZYX 
2, 整体翻转：XYZdefabc.
*/

string LeftRotateString(string str, int n) {
	int size = str.size();
	if (size <= 1) return str;
	n = n % size;//移动查过size次，就等于没有移动。
	//分别翻转
	reverse_string(str, 0, n - 1);
	reverse_string(str, n, size - 1);
	//整体翻转
	reverse_string(str, 0, size - 1);
	return str;
}
//翻转函数
void reverse_string(string &str, int start, int end) {
	while (start <= end) {
		swap(str[start], str[end]);
		start++; end--;
	}
}