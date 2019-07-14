/*
��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��




˼·��һ��Ҫ�������һ������С��ǰ��һ�������֣����ں���һ�������֡�
*/


bool VerifySquenceOfBST(vector<int> sequence) {
	int n = sequence.size();
	if (n == 0) return false;
	return find(sequence, 0, n - 1);//�鿴��ʼλ�úͽ���λ��֮���ǲ��Ǻ������
}
bool find(vector<int> &q, int start, int end) {
	if (end - start < 2) return true;//����С�ڵ���2������һ�������
	int index = start;
	//��ѯ����������
	while (index < end && q[index] < q[end]) {
		index++;
	}
	//��ѯ����������
	int right_index = index;
	while (right_index < end && q[right_index] >= q[end]) {
		right_index++;
	}
	//����������ã�˵���ֿ��Գ�Ϊ����������
	if (right_index == end) {
		return find(q, start, index - 1) && find(q, index, end - 1);
	}
	else return false;
}