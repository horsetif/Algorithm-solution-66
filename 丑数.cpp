/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。


思路：设置三个指针，分别指向三个不同不同乘子。
*/

int GetUglyNumber_Solution(int index) {
	if (index <= 0) return 0;
	if (index == 1) return 1;
	vector<int> num(index, 0);
	num[0] = 1;
	int idx_2 = 0, idx_3 = 0, idx_5 = 0;
	for (int i = 1; i < index; i++) {
		//更新索引值,达到最边缘值
		while (num[idx_2] * 2 <= num[i - 1]) idx_2++;
		while (num[idx_3] * 3 <= num[i - 1]) idx_3++;
		while (num[idx_5] * 5 <= num[i - 1]) idx_5++;
		//更新下一个值
		num[i] = get_min(num[idx_2] * 2, num[idx_3] * 3, num[idx_5] * 5);
	}
	return num[index - 1];
}
int get_min(int a, int b, int c) {
	return min(min(a, b), c);
}