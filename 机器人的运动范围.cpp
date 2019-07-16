/*
题目描述
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？


思路：典型的BFS。每次检查mask，如果查过了就不用再查了。
*/

int movingCount(int threshold, int rows, int cols) {
	bool *mask = new bool[rows*cols];
	memset(mask, 0, sizeof(bool)*rows*cols);
	int cnt = 0;
	find(threshold, rows, cols, 0, 0, cnt, mask);
	return cnt;
}
void find(int thres, int rows, int cols, int row, int col, int &cnt, bool* mask) {
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		!mask[row*cols + col]) {
		mask[row*cols + col] = true;
		int num = 0;
		//计算索引数之和
		int r = row, c = col;
		while (r != 0) {
			num += r % 10;
			r = r / 10;
		}
		while (c != 0) {
			num += c % 10;
			c = c / 10;
		}
		if (num > thres) return;
		cnt++;
		//各个方向查找
		find(thres, rows, cols, row + 1, col, cnt, mask);
		find(thres, rows, cols, row - 1, col, cnt, mask);
		find(thres, rows, cols, row, col - 1, cnt, mask);
		find(thres, rows, cols, row, col + 1, cnt, mask);
	}
	return;
}