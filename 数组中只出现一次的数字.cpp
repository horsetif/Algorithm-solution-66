/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。


思路：所有数字都异或一遍之后，得到的数字就是两个单独数字的异或。
然后基于结果其中一位是否为1，来把整个数组分离成两部分，然后再分别异或一遍。得到两个结果。
*/

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	//第一步，先整体异或一遍，得到一个两个数字的异或值
	int res = 0;
	for (auto d : data) res = res ^ d;
	//第二步，找到一位为1
	int ind = 0;
	while ((res & 1) == 0) {
		res = res >> 1;
		ind++;
	}
	//第三步，基于特定位是不是1分两类，然后各自异或
	int res1 = 0, res2 = 0;
	for (auto d : data) {
		if (is_bit(d, ind)) res1 = res1 ^ d;
		else res2 = res2 ^ d;
	}
	*num1 = res1;
	*num2 = res2;
	return;
}
//查看特定位是不是1
bool is_bit(int d, int ind) {
	d = d >> ind;
	return (d & 1);
}