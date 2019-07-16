/*
��Ŀ����
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���


˼·������hash��256����ÿһλ��Ӧ���ֵ�λ�á�
���û�г��ֹ�����ô������Ϊ-1������ظ����ֹ�����ô������Ϊ-2.
���ҵ�ʱ��������ң��ҵ���С�Ķ�Ӧֵ�Ϳ��ԡ�
*/
//��ʼ״̬Ϊ-1.
vector<int> find = vector<int>(256, -1);
int index = 0;
//Insert one char from stringstream
void Insert(char ch) {
	//���û�в�����ͼ�¼��һ�γ��ֵ�λ��
	if (find[ch] == -1) find[ch] = index;
	//�������ˣ���ô�ͼ�¼-2����ʾ�ظ�������
	else if (find[ch] >= 0) find[ch] = -2;
	index++;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce() {
	int min_index = INT_MAX, res = 0;
	//����index��С��ֵ
	for (int i = 0; i < 256; i++) {
		if (find[i] >= 0 && find[i] < min_index) {
			min_index = find[i];
			res = i;
		}
	}
	if (min_index == INT_MAX) return '#';
	else return char(res);
}