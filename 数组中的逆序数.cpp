/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5

示例1
输入
1,2,3,4,5,6,7,0
输出
7


思路：很明显是归并排序。数组要增加一个相互转换数组。
*/

int InversePairs(vector<int> data) {
	vector<int> copy(data);
	int n = data.size();
	if (n <= 1) return 0;
	return inverse(data, copy, 0, n - 1) % 1000000007;
}
int inverse(vector<int> &data, vector<int> &copy, int start, int end) {
	if (end == start) {
		copy[start] = data[start];
		return 0;
	}
	int len = (end - start) / 2;//中间数
	//递归操作，分别计算两部分的值
	//实际上是把data给调整通顺了
	int left = inverse(copy, data, start, start + len) % 1000000007;
	int right = inverse(copy, data, start + len + 1, end) % 1000000007;
	//合并操作，把两部分合并在一起，这里就有逆序计算
	int i = start + len, j = end; // 两边数组的最后一个值
	int cnt = 0, index = end;//cnt :总的计算值,index:copy 后的索引
	while (i >= start && j >= start + len + 1) {
		//如果后面的大一些，就直接添加到copy中，没有逆序值
		if (data[i] <= data[j]) copy[index--] = data[j--];
		//如果前面的大一些，那么需要计算逆序数
		else {
			if (cnt >= 1000000007) cnt = cnt % 1000000007;
			//添加逆序数，逆序数为右数组当前查找位到最前面的所有数字
			cnt += (j - start - len);
			copy[index--] = data[i--];
		}
	}
	//把没有计算完的补充上
	for (; i >= start; i--) copy[index--] = data[i];
	for (; j >= start + len + 1; j--) copy[index--] = data[j];
	return (left + right + cnt) % 1000000007;
}