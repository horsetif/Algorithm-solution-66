/*
��Ŀ����
���磬��student. a am I����
��ȷ�ľ���Ӧ���ǡ�I am a student.����


����˼·��1�����뵥�ʣ�����ϡ�������������У�������Чʶ���ո������
2����ת�������ӣ�Ȼ�����ÿһ�������ٷ�ת��
*/

string ReverseSentence(string str) {
	//���巭ת
	int n = str.size();
	reverse_str(str, 0, n - 1);
	//�����ַ���
	bool in_word = false;
	int index = -1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			//���֮ǰ��û�п�ʼ��飬��ô����������־λ��
			if (!in_word) {
				in_word = true; index = i;
			}
		}
		else {
			//�����ո�֮ǰ����Ǽ��״̬���ͷ�ת
			if (in_word) {
				reverse_str(str, index, i - 1);
			}
			in_word = false;
		}
	}
	//��β���ּ��
	if (in_word) reverse_str(str, index, n - 1);
	return str;
}
void reverse_str(string &str, int begin, int end) {
	while (begin <= end) {
		swap(str[begin], str[end]);
		begin++; end--;
	}
}