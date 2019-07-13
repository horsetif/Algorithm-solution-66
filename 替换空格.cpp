/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。



思路：字符串后移操作。首先统计字符串中的空格数 n。然后在字符串后面新开辟 2n的空间用来保存其他字符。然后从后往前遍历。如果不是空格，那么往后移动。如果是空格，那么添加%20这三个数字。
	注意输入的是char*的空间指针。
*/

void replaceSpace(char *str, int length) {
	char *head = str;
	int len = 0, space_len = 0;//查找字符长度，以及空格的总长度。
	while (*head != '\0') {
		if (*head == ' ') space_len++;
		len++;
		head++;
	}
	int new_len = len + 2 * space_len;
	str[new_len--] = '\0';//设置字符最后一位
	len--;
	while (len >= 0) {
		//不是空格的情况，那么就直接后移就行
		if (str[len] != ' ') {
			str[new_len--] = str[len--];
		}
		//是空格的情况，就把特殊字符加上去。
		else {
			len--;
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len--] = '%';
		}
	}
}