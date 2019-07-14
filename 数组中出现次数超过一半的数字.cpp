/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。



思路：切分法。不停切分，使得左边小于切分值，右边大于切分值。
直到切分位置为长度的一半。然后计算切分左侧是不是都是相同的数字，就可以。
*/


int MoreThanHalfNum_Solution(vector<int> numbers) {
	int n = numbers.size();
	if (n == 0) return 0;
	if (n == 1) return numbers[0];
	int par_index = partition(numbers, 0, n - 1);
	//查找切分索引
	int mid = n / 2, start = 0, end = n - 1;
	while (par_index != mid) {
		if (par_index < mid) {
			start = par_index + 1;
			par_index = partition(numbers, start, end);
		}
		else {
			end = par_index - 1;
			par_index = partition(numbers, start, end);
		}
	}
	//检查是否值都一样
	int find_num = numbers[n / 2], len = 0;
	for (int i = 0; i < n; i++) {
		if (numbers[i] == find_num) len++;
	}
	if (len > n / 2) return find_num;
	else return 0;
}
int partition(vector<int> &numbers, int start, int end) {
	int index = rand() % (end - start + 1) + start;//创建切分位置
	swap(numbers[index], numbers[end]);//把切分位置放在最后
	int small = start - 1;
	//保证小的数字在左边，大的数字在右边
	for (int i = start; i < end; i++) {
		if (numbers[i] <= numbers[end]) {
			small++;
			swap(numbers[small], numbers[i]);
		}
	}
	small++;
	swap(numbers[small], numbers[end]);
	return small;
}