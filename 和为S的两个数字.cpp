/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。


思路：二分查找。固定一个数字，然后在数组中查找另外一个。关键如何处理重复。
还有一种想法，不用考虑重复。设置两个指针index1= 0,index2 =n-1.
如果和大于target，那么index2--.如果和小于target，那么index1++.直到两个相遇。
*/

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	int n = array.size();
	int start = 0, end = n - 1;
	vector<int> ans;
	while (start < end) {
		//如果目标和值小于sum，那么start++。否则end++。
		int target = array[start] + array[end];
		if (target < sum) start++;
		else if (target > sum) end--;
		else {//如果相同，那么检查乘积是否最小。
			if (ans.empty() || array[start] * array[end] < ans[0] * ans[1]) {
				ans.push_back(array[start]);
				ans.push_back(array[end]);
			}
			start++;
		}
	}
	return ans;
}