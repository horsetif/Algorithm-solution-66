/*
��Ŀ����
һ�����������������������֮�⣬���������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�


˼·���������ֶ����һ��֮�󣬵õ������־��������������ֵ����
Ȼ����ڽ������һλ�Ƿ�Ϊ1�����������������������֣�Ȼ���ٷֱ����һ�顣�õ����������
*/

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	//��һ�������������һ�飬�õ�һ���������ֵ����ֵ
	int res = 0;
	for (auto d : data) res = res ^ d;
	//�ڶ������ҵ�һλΪ1
	int ind = 0;
	while ((res & 1) == 0) {
		res = res >> 1;
		ind++;
	}
	//�������������ض�λ�ǲ���1�����࣬Ȼ��������
	int res1 = 0, res2 = 0;
	for (auto d : data) {
		if (is_bit(d, ind)) res1 = res1 ^ d;
		else res2 = res2 ^ d;
	}
	*num1 = res1;
	*num2 = res2;
	return;
}
//�鿴�ض�λ�ǲ���1
bool is_bit(int d, int ind) {
	d = d >> ind;
	return (d & 1);
}