/*
��ά�����еĲ���
��Ŀ����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������



����˼·��
�Խǲ��ҷ��������Ͻǿ�ʼ���ң�������ֵС��target��˵�������ж�С��target����ôɾ����ǰ�С�������ֵ����target����ô˵�������ж�С��target��ɾ����ǰ�С�������˼������Ҫ�½�mask��Ҳ����Ҫ�ݹ顣
*/

bool Find(int target, vector<vector<int> > array) {
	//���������
	int m = array.size();
	if (m == 0) return false;
	int n = array[0].size();
	if (n == 0) return false;
	//�����Ͻǿ�ʼ���
	int row = 0, col = n - 1;
	while (row < m && col >= 0) {//�߽�ȷ��
		if (array[row][col] == target) return true;
		if (array[row][col] > target) col--; // ˵�������ж���target����ô���в�����
		else row++;//˵�������ж���targetС����ô���в�����
	}
	return false;
}