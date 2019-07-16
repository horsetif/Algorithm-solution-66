/*
��Ŀ����
������һ��m�к�n�еķ���
һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19��
���ʸû������ܹ��ﵽ���ٸ����ӣ�


˼·�����͵�BFS��ÿ�μ��mask���������˾Ͳ����ٲ��ˡ�
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
		//����������֮��
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
		//�����������
		find(thres, rows, cols, row + 1, col, cnt, mask);
		find(thres, rows, cols, row - 1, col, cnt, mask);
		find(thres, rows, cols, row, col - 1, cnt, mask);
		find(thres, rows, cols, row, col + 1, cnt, mask);
	}
	return;
}