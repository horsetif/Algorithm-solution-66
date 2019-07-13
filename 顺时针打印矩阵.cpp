/*
��Ŀ����
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬�����������4 X 4���� [[1 2 3 4] 
							   [ 5 6 7 8]
							   [9 10 11 12] 
							   [13 14 15 16]]
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.



˼·���Ƚ��鷳��Ҫ����Լ����Ҫ����Լ���ֱ���������ߡ�start_pos = (0,0) -> (1,1) -> (2,2)
	����С������Լ����
*/

vector<int> ans;
vector<int> printMatrix(vector<vector<int> > matrix) {
	int m = matrix.size();
	if (m == 0) return ans;
	int n = matrix[0].size();
	if (n == 0) return ans;//��ʼ����
	int start_pos = 0;
	//��ʼ��һ��Ҫ����������Ҫô��˵���Ѿ����ҹ���
	while (start_pos * 2 < m && start_pos * 2 < n) {
		find(matrix, start_pos, m, n);
		start_pos++;
	}
	return ans;
}
void find(vector<vector<int>> &matrix, int start_pos, int m, int n) {
	int x = start_pos, y = start_pos;//��ʼ���ҵ�,x����ֱ����ģ�y�Ǻ��ŵ�
	//��һ�������Ų�
	for (int i = y; i <= n - 1 - y; i++)
		ans.push_back(matrix[x][i]);
	//�ڶ������ұ����Ų�
	for (int j = x + 1; j <= m - 1 - x; j++)
		ans.push_back(matrix[j][n - 1 - y]);
	//�����������µ��Ų飬�������ע�⣬��������в�������
	if (m - 1 - x > x) {//ע�⣬x��y�������򶼱������ල������ֻ�ලx������Ӧ��forѭ������y����ļල
		for (int i = n - 1 - y - 1; i >= y; i--)
			ans.push_back(matrix[m - 1 - x][i]);
	}
	//���Ĳ����ײ����ϲ�
	if (n - 1 - y > y) {//ͬ������Ҫ���ල
		for (int j = m - 1 - x - 1; j >= x + 1; j--)
			ans.push_back(matrix[j][x]);
	}
}