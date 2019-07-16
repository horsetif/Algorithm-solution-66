/*
��Ŀ����
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�



˼·��ѡ��̫�࣬�о�Ҫ��״̬ת�Ʒ�������״̬ת�Ʒ�����̫�����ˡ�
��Ϊ������鷨��1�����С����֮ǰ���ǲ���������
2�����С���������ǲ����޷����������������С���㣬����12����Ҫ����һ����
3�����E������ǲ����������������E��������Ҫ���㣩
*/

bool isNumeric(char* string) {
	if (string == NULL) return false;
	//��һ�������С����ǰ���ǲ�����������������������
	bool numeric = isNumer(&string);
	//�ڶ��������С��������ǲ����޷���������С����ǰ����һ�������ͺ���
	if (*string == '.') {
		string++;
		numeric = isUnsignedNumer(&string) || numeric;
	}
	//�����������e/E�����ǲ�������
	if (*string == 'e' || *string == 'E') {
		string++;
		//�����E������һ��Ҫ������
		numeric = isNumer(&string) && numeric;
	}
	return numeric && (*string == '\0');
}
//�����з�������
bool isNumer(char ** str) {
	if (**str == '+' || **str == '-')
		++(*str);
	return isUnsignedNumer(str);
}
//�����޷�������
bool isUnsignedNumer(char **str) {
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
	return (*str) > before;
}