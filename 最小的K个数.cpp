/*
题目描述
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。



思路：同样利用切分索引，让索引值为K即可。
*/

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> ans;
	int n = input.size();
	if (n < k) return ans;
	if (n == k) return input;
	int par_index = partition(input, 0, n - 1);
	int start = 0, end = n - 1;
	//二分查找到k的切分值
	while (par_index != k) {
		if (par_index < k) {
			start = par_index + 1;
			par_index = partition(input, start, end);
		}
		else {
			end = par_index - 1;
			par_index = partition(input, start, end);
		}
	}
	//导入
	for (int i = 0; i < k; i++) ans.push_back(input[i]);
	return ans;
}
//切分查找函数
int partition(vector<int> &input, int start, int end) {
	int index = rand() % (end - start + 1) + start;
	int small = start - 1;
	swap(input[index], input[end]);
	for (int i = start; i < end; i++) {
		if (input[i] < input[end]) {
			small++;
			if (small != i) swap(input[small], input[i]);
		}
	}
	small++;
	swap(input[small], input[end]);
	return small;
}