/*
��Ŀ����
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�
���� 
a b c e
s f c s
a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·����
���Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�



˼·�����ݱ�����
*/

bool hasPath(char* matrix, int rows, int cols, char* str) {
	bool *mask = new bool[rows*cols];
	memset(mask, 0, rows*cols * sizeof(bool));
	int len = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//ÿһ���ڵ㶼����һ��
			bool res = find(matrix, mask, rows, cols, str, len, i, j);
			if (res) return true;
		}
	}
	return false;
}
bool find(char* matrix, bool* mask, int rows, int cols, char* str, int &len, int row, int col) {
	//�鵽���ˣ�˵���Ѿ�������
	if (str[len] == '\0') return true;
	bool res = false;
	//��������Ե��ϣ�����û�м���
	if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols + col] == str[len]
		&& !mask[row*cols + col]) {
		mask[row*cols + col] = true;
		//�����һ���ڵ�
		len++;
		res = find(matrix, mask, rows, cols, str, len, row + 1, col) ||
			find(matrix, mask, rows, cols, str, len, row - 1, col) ||
			find(matrix, mask, rows, cols, str, len, row, col + 1) ||
			find(matrix, mask, rows, cols, str, len, row, col - 1);
		//����
		if (!res) {
			mask[row*cols + col] = false;
			len--;
		}
	}
	return res;

}