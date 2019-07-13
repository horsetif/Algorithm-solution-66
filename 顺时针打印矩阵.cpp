/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： [[1 2 3 4] 
							   [ 5 6 7 8]
							   [9 10 11 12] 
							   [13 14 15 16]]
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.



思路：比较麻烦，要考虑约束。要按照约束分别计算四条边。start_pos = (0,0) -> (1,1) -> (2,2)
	必须小心条件约束。
*/

vector<int> ans;
vector<int> printMatrix(vector<vector<int> > matrix) {
	int m = matrix.size();
	if (m == 0) return ans;
	int n = matrix[0].size();
	if (n == 0) return ans;//初始查找
	int start_pos = 0;
	//初始点一定要满足条件，要么就说明已经查找过了
	while (start_pos * 2 < m && start_pos * 2 < n) {
		find(matrix, start_pos, m, n);
		start_pos++;
	}
	return ans;
}
void find(vector<vector<int>> &matrix, int start_pos, int m, int n) {
	int x = start_pos, y = start_pos;//初始查找点,x是竖直方向的，y是横着的
	//第一步，横着查
	for (int i = y; i <= n - 1 - y; i++)
		ans.push_back(matrix[x][i]);
	//第二步，右边竖着查
	for (int j = x + 1; j <= m - 1 - x; j++)
		ans.push_back(matrix[j][n - 1 - y]);
	//第三步，底下倒着查，这里必须注意，这里可能有不查的情况
	if (m - 1 - x > x) {//注意，x和y两个方向都必须做监督。这里只监督x方向，是应该for循环会做y方向的监督
		for (int i = n - 1 - y - 1; i >= y; i--)
			ans.push_back(matrix[m - 1 - x][i]);
	}
	//第四步，底部往上查
	if (n - 1 - y > y) {//同样必须要做监督
		for (int j = m - 1 - x - 1; j >= x + 1; j--)
			ans.push_back(matrix[j][x]);
	}
}