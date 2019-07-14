/*
��Ŀ����
����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4��



˼·��ͬ�������з�������������ֵΪK���ɡ�
*/

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> ans;
	int n = input.size();
	if (n < k) return ans;
	if (n == k) return input;
	int par_index = partition(input, 0, n - 1);
	int start = 0, end = n - 1;
	//���ֲ��ҵ�k���з�ֵ
	while (par_index != k) {
		if (par_index < k) {
			start = par_index + 1;
			par_index = partition(input, start, end);
		}
		else {
			end = par_index - 1;
			par_index = partition(input, start, end);
		}
	}
	//����
	for (int i = 0; i < k; i++) ans.push_back(input[i]);
	return ans;
}
//�зֲ��Һ���
int partition(vector<int> &input, int start, int end) {
	int index = rand() % (end - start + 1) + start;
	int small = start - 1;
	swap(input[index], input[end]);
	for (int i = start; i < end; i++) {
		if (input[i] < input[end]) {
			small++;
			if (small != i) swap(input[small], input[i]);
		}
	}
	small++;
	swap(input[small], input[end]);
	return small;
}