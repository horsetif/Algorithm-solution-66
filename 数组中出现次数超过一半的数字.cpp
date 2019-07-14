/*
��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��



˼·���зַ�����ͣ�з֣�ʹ�����С���з�ֵ���ұߴ����з�ֵ��
ֱ���з�λ��Ϊ���ȵ�һ�롣Ȼ������з�����ǲ��Ƕ�����ͬ�����֣��Ϳ��ԡ�
*/


int MoreThanHalfNum_Solution(vector<int> numbers) {
	int n = numbers.size();
	if (n == 0) return 0;
	if (n == 1) return numbers[0];
	int par_index = partition(numbers, 0, n - 1);
	//�����з�����
	int mid = n / 2, start = 0, end = n - 1;
	while (par_index != mid) {
		if (par_index < mid) {
			start = par_index + 1;
			par_index = partition(numbers, start, end);
		}
		else {
			end = par_index - 1;
			par_index = partition(numbers, start, end);
		}
	}
	//����Ƿ�ֵ��һ��
	int find_num = numbers[n / 2], len = 0;
	for (int i = 0; i < n; i++) {
		if (numbers[i] == find_num) len++;
	}
	if (len > n / 2) return find_num;
	else return 0;
}
int partition(vector<int> &numbers, int start, int end) {
	int index = rand() % (end - start + 1) + start;//�����з�λ��
	swap(numbers[index], numbers[end]);//���з�λ�÷������
	int small = start - 1;
	//��֤С����������ߣ�����������ұ�
	for (int i = start; i < end; i++) {
		if (numbers[i] <= numbers[end]) {
			small++;
			swap(numbers[small], numbers[i]);
		}
	}
	small++;
	swap(numbers[small], numbers[end]);
	return small;
}