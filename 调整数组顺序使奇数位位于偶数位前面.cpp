/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。



思路：利用冒泡法。从后往前冒泡，如果冒泡对象是[偶，奇]类型的，那么就翻转。否则不翻转。
*/

void reOrderArray(vector<int> &array) {
	int n = array.size();
	//利用冒泡法
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) { //遍历一次之后，其实头已经遍历好了，不需要再计算
			if (array[j - 1] % 2 == 0 && array[j] % 2 == 1) {//翻转对为偶，奇 类型，才可以翻转
				swap(array[j - 1], array[j]);
			}
		}
	}
	return;
}