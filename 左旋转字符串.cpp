/*
��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
�������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����



˼·���ֲ���ת���ȷֱ�תһ�Σ�Ȼ�������巭תһ�Ρ�
1���ֱ�ת�� cba fedZYX 
2, ���巭ת��XYZdefabc.
*/

string LeftRotateString(string str, int n) {
	int size = str.size();
	if (size <= 1) return str;
	n = n % size;//�ƶ����size�Σ��͵���û���ƶ���
	//�ֱ�ת
	reverse_string(str, 0, n - 1);
	reverse_string(str, n, size - 1);
	//���巭ת
	reverse_string(str, 0, size - 1);
	return str;
}
//��ת����
void reverse_string(string &str, int start, int end) {
	while (start <= end) {
		swap(str[start], str[end]);
		start++; end--;
	}
}