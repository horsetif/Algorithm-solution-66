/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。


思路：设置hash表。256个，每一位对应出现的位置。
如果没有出现过，那么就设置为-1。如果重复出现过，那么就设置为-2.
查找的时候逐个查找，找到最小的对应值就可以。
*/
//初始状态为-1.
vector<int> find = vector<int>(256, -1);
int index = 0;
//Insert one char from stringstream
void Insert(char ch) {
	//如果没有查过，就记录第一次出现的位置
	if (find[ch] == -1) find[ch] = index;
	//如果查过了，那么就记录-2，表示重复查找了
	else if (find[ch] >= 0) find[ch] = -2;
	index++;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce() {
	int min_index = INT_MAX, res = 0;
	//查找index最小的值
	for (int i = 0; i < 256; i++) {
		if (find[i] >= 0 && find[i] < min_index) {
			min_index = find[i];
			res = i;
		}
	}
	if (min_index == INT_MAX) return '#';
	else return char(res);
}