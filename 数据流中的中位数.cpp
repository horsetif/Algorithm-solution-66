/*
��Ŀ����
��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����



˼·���������Ѻ���С������������ǰ�沿�ַ�����������沿�ַ�����С���
���������������ͬ����ô���ȷ������ѣ�ǰ�沿�֣���
�����Ҫ��������ʱ����ôһ��Ҫ�Ƚ�����С������Ȼ�󵯳����ֵ�����뵽�����С�
ͬ����������С��ʱ��Ҫ�Ƚ�����������Ȼ�󵯳����ֵ�������ֵ���뵽��С���С�
�������ܱ���ƽ�⡣
*/

vector<int> max;
vector<int> min;
int tmp;
void Insert(int num) {
	//���������������ͬ����ô���ȼ�������
	if (max.size() == min.size()) {
		//������С�Ѹ���һ�飬Ȼ������������
		min.push_back(num);
		push_heap(min.begin(), min.end(), greater<int>());
		tmp = min[0];
		pop_heap(min.begin(), min.end(), greater<int>());
		min.pop_back();
		max.push_back(tmp);
		push_heap(max.begin(), max.end(), less<int>());
	}
	//�������ͬ��˵�����Ѷ��ˣ�Ҫ��ӵ���С����
	else {//�������������һ��
		max.push_back(num);
		push_heap(max.begin(), max.end(), less<int>());
		tmp = max[0];
		pop_heap(max.begin(), max.end(), less<int>());
		max.pop_back();
		min.push_back(tmp);
		push_heap(min.begin(), min.end(), greater<int>());
	}
}

double GetMedian() {
	//��ͬ�ͷ����м�ֵ������ͬ�ͷ������ѵ�ֵ
	if (max.size() == min.size()) {
		int num1 = min[0], num2 = max[0];
		return double(num1 + num2) / 2;
	}
	else {
		return max[0];
	}
}