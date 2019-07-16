/*
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
例如 
a b c e
s f c s
a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。



思路：回溯遍历。
*/

bool hasPath(char* matrix, int rows, int cols, char* str) {
	bool *mask = new bool[rows*cols];
	memset(mask, 0, rows*cols * sizeof(bool));
	int len = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//每一个节点都遍历一次
			bool res = find(matrix, mask, rows, cols, str, len, i, j);
			if (res) return true;
		}
	}
	return false;
}
bool find(char* matrix, bool* mask, int rows, int cols, char* str, int &len, int row, int col) {
	//查到底了，说明已经结束了
	if (str[len] == '\0') return true;
	bool res = false;
	//如果这个点对得上，而且没有检查过
	if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols + col] == str[len]
		&& !mask[row*cols + col]) {
		mask[row*cols + col] = true;
		//检查下一个节点
		len++;
		res = find(matrix, mask, rows, cols, str, len, row + 1, col) ||
			find(matrix, mask, rows, cols, str, len, row - 1, col) ||
			find(matrix, mask, rows, cols, str, len, row, col + 1) ||
			find(matrix, mask, rows, cols, str, len, row, col - 1);
		//回溯
		if (!res) {
			mask[row*cols + col] = false;
			len--;
		}
	}
	return res;

}