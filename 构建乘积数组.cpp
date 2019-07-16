/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。


思路：构建一个n*n的矩阵，其中对角线为1.
从上向下添加左下矩阵。从下向上添加右上矩阵。这种添加可以直接乘积。
*/

vector<int> multiply(const vector<int>& A) {
	int n = A.size();
	vector<int> ans(n, 1);
	if (n <= 1) return ans;
	int tmp = 1;//当前值
	for (int i = 1; i < n; i++) {//计算左下角，从上到下
		tmp = tmp * A[i - 1];
		ans[i] = ans[i] * tmp;
	}
	tmp = 1;
	for (int i = n - 2; i >= 0; i--) {//计算右上角，从下到上
		tmp = tmp * A[i + 1];
		ans[i] = ans[i] * tmp;
	}
	return ans;
}