/*
��Ŀ����
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P��
����P��1000000007ȡģ�Ľ������� �����P%1000000007
��������:
��Ŀ��֤�����������û�е���ͬ������

���ݷ�Χ��

	����%50������,size<=10^4

	����%75������,size<=10^5

	����%100������,size<=2*10^5

ʾ��1
����
1,2,3,4,5,6,7,0
���
7


˼·���������ǹ鲢��������Ҫ����һ���໥ת�����顣
*/

int InversePairs(vector<int> data) {
	vector<int> copy(data);
	int n = data.size();
	if (n <= 1) return 0;
	return inverse(data, copy, 0, n - 1) % 1000000007;
}
int inverse(vector<int> &data, vector<int> &copy, int start, int end) {
	if (end == start) {
		copy[start] = data[start];
		return 0;
	}
	int len = (end - start) / 2;//�м���
	//�ݹ�������ֱ���������ֵ�ֵ
	//ʵ�����ǰ�data������ͨ˳��
	int left = inverse(copy, data, start, start + len) % 1000000007;
	int right = inverse(copy, data, start + len + 1, end) % 1000000007;
	//�ϲ��������������ֺϲ���һ����������������
	int i = start + len, j = end; // ������������һ��ֵ
	int cnt = 0, index = end;//cnt :�ܵļ���ֵ,index:copy �������
	while (i >= start && j >= start + len + 1) {
		//�������Ĵ�һЩ����ֱ����ӵ�copy�У�û������ֵ
		if (data[i] <= data[j]) copy[index--] = data[j--];
		//���ǰ��Ĵ�һЩ����ô��Ҫ����������
		else {
			if (cnt >= 1000000007) cnt = cnt % 1000000007;
			//�����������������Ϊ�����鵱ǰ����λ����ǰ�����������
			cnt += (j - start - len);
			copy[index--] = data[i--];
		}
	}
	//��û�м�����Ĳ�����
	for (; i >= start; i--) copy[index--] = data[i];
	for (; j >= start + len + 1; j--) copy[index--] = data[j];
	return (left + right + cnt) % 1000000007;
}