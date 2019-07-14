/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。
可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。



思路：比如计算 1-35618。那么分成两部分。[1-5618] 和 [5619 - 35618].
我们看第二部分。如果最高位3. 如果最高位大于1，那么就有10000个1。如果最高位为1，那么就有5618个1.
再看后面4位。每个位为1，其他三位都是任意数字。4*1000*3，这里的3是最高位总次数。
然后再递归计算第一部分。
总的和就是我们要计算的数字。
*/
int NumberOf1Between1AndN_Solution(int n) {
	string str = to_string(n);
	int size = str.size();//数字的长度
	return find(str);
}
int find(string str) {
	int size = str.size();
	if (size == 0) return 0;
	if (size == 1 && str[0] >= '1') return 1;
	if (size == 1) return 0;
	string sub_string = str.substr(1);
	int res = 0;
	//看第一个数字，如果为1，那么就单独处理。如果不是1.那么就是后面的位数。
	int find_num = str[0] - '0';
	if (find_num == 1) {
		stringstream ss;
		//获取后面数字
		int res_num = 0;
		ss << sub_string;
		ss >> res_num;
		res = res + res_num + 1;
	}
	else if (find_num > 1) res += exp10(size - 1);
	//find_num == 0 的情况可以跳过考虑
	//计算后面几位
	res += (exp10(size - 2) * (size - 1) * find_num);
	//剩下几位
	res += find(sub_string);
	return res;
}
int exp10(int size) {
	int base = 1;
	if (size == 0) return base;
	while (size-- > 0) base = base * 10;
	return base;
}
