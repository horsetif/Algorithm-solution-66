/*
二维数组中的查找
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。



解题思路：
对角查找法。从右上角开始查找，如果这个值小于target，说明整个行都小于target，那么删除当前行。如果这个值大于target，那么说明整个列都小于target，删除当前列。很有意思。不需要新建mask，也不需要递归。
*/

bool Find(int target, vector<vector<int> > array) {
	//常规检查操作
	int m = array.size();
	if (m == 0) return false;
	int n = array[0].size();
	if (n == 0) return false;
	//从右上角开始检查
	int row = 0, col = n - 1;
	while (row < m && col >= 0) {//边界确认
		if (array[row][col] == target) return true;
		if (array[row][col] > target) col--; // 说明整个列都比target大，那么这列不查找
		else row++;//说明整个行都比target小，那么这行不查找
	}
	return false;
}