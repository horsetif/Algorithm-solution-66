/*
题目描述
例如，“student. a am I”。
正确的句子应该是“I am a student.”。


两种思路：1，分离单词，重组合。（这个方法不行，不能有效识别多空格情况。
2，翻转整个句子，然后对于每一个单词再翻转。
*/

string ReverseSentence(string str) {
	//整体翻转
	int n = str.size();
	reverse_str(str, 0, n - 1);
	//分离字符串
	bool in_word = false;
	int index = -1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			//如果之前还没有开始检查，那么设置启动标志位。
			if (!in_word) {
				in_word = true; index = i;
			}
		}
		else {
			//遇到空格，之前如果是检查状态，就翻转
			if (in_word) {
				reverse_str(str, index, i - 1);
			}
			in_word = false;
		}
	}
	//结尾数字检测
	if (in_word) reverse_str(str, index, n - 1);
	return str;
}
void reverse_str(string &str, int begin, int end) {
	while (begin <= end) {
		swap(str[begin], str[end]);
		begin++; end--;
	}
}