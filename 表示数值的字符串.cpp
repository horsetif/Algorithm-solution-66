/*
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。



思路：选择太多，感觉要用状态转移法。但是状态转移法还是太烦人了。
分为三步检查法。1，检查小数点之前的是不是整数。
2，检查小数点后面的是不是无符号整数。（如果有小数点，步骤12至少要满足一个）
3，检查E后面的是不是整数。（如果有E，三必须要满足）
*/

bool isNumeric(char* string) {
	if (string == NULL) return false;
	//第一步，检查小数点前的是不是整数，这个整数必须存在
	bool numeric = isNumer(&string);
	//第二步，检查小数点后面是不是无符号整数，小数点前后，有一个成立就好了
	if (*string == '.') {
		string++;
		numeric = isUnsignedNumer(&string) || numeric;
	}
	//第三步，检查e/E后面是不是整数
	if (*string == 'e' || *string == 'E') {
		string++;
		//如果有E，后面一定要跟整数
		numeric = isNumer(&string) && numeric;
	}
	return numeric && (*string == '\0');
}
//查找有符号数字
bool isNumer(char ** str) {
	if (**str == '+' || **str == '-')
		++(*str);
	return isUnsignedNumer(str);
}
//查找无符号数字
bool isUnsignedNumer(char **str) {
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
	return (*str) > before;
}