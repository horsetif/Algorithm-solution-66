/*
��Ŀ����
��ֻ����������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ������������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������


˼·����������ָ�룬�ֱ�ָ��������ͬ��ͬ���ӡ�
*/

int GetUglyNumber_Solution(int index) {
	if (index <= 0) return 0;
	if (index == 1) return 1;
	vector<int> num(index, 0);
	num[0] = 1;
	int idx_2 = 0, idx_3 = 0, idx_5 = 0;
	for (int i = 1; i < index; i++) {
		//��������ֵ,�ﵽ���Եֵ
		while (num[idx_2] * 2 <= num[i - 1]) idx_2++;
		while (num[idx_3] * 3 <= num[i - 1]) idx_3++;
		while (num[idx_5] * 5 <= num[i - 1]) idx_5++;
		//������һ��ֵ
		num[i] = get_min(num[idx_2] * 2, num[idx_3] * 3, num[idx_5] * 5);
	}
	return num[index - 1];
}
int get_min(int a, int b, int c) {
	return min(min(a, b), c);
}