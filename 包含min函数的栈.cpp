/*
��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������



˼·������һ����ջ��ר�Ű���ջ�е���СԪ�ء�
�������һ����Ԫ�ر���Сջ��ջ��Ԫ��С����ô��ֱ�Ӽ�����Ԫ�ء�
����������Ԫ�ر���Сջ��ջ��Ԫ�ش���ô���ظ�����ջ��Ԫ�ء�
*/

stack<int> data;
stack<int> data_min;
void push(int value) {
	data.push(value);
	if (data_min.empty()) {
		data_min.push(value);
	}
	else {
		//�Ϳ���ӵ�Ԫ���ǲ��Ǳ�ջ��Ԫ��С��С��ֱ����ӡ�����ظ���ӡ�
		int tmp = data_min.top();
		if (value > tmp) data_min.push(tmp);
		else data_min.push(value);
	}
}
void pop() {
	data.pop();
	data_min.pop();
}
int top() {
	return data.top();
}
int min() {
	return data_min.top();
}