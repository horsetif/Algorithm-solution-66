/*
��Ŀ����
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
���Ƕ��ں�����������û���ˡ�
���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������



˼·��������� 1-35618����ô�ֳ������֡�[1-5618] �� [5619 - 35618].
���ǿ��ڶ����֡�������λ3. ������λ����1����ô����10000��1��������λΪ1����ô����5618��1.
�ٿ�����4λ��ÿ��λΪ1��������λ�����������֡�4*1000*3�������3�����λ�ܴ�����
Ȼ���ٵݹ�����һ���֡�
�ܵĺ;�������Ҫ��������֡�
*/
int NumberOf1Between1AndN_Solution(int n) {
	string str = to_string(n);
	int size = str.size();//���ֵĳ���
	return find(str);
}
int find(string str) {
	int size = str.size();
	if (size == 0) return 0;
	if (size == 1 && str[0] >= '1') return 1;
	if (size == 1) return 0;
	string sub_string = str.substr(1);
	int res = 0;
	//����һ�����֣����Ϊ1����ô�͵��������������1.��ô���Ǻ����λ����
	int find_num = str[0] - '0';
	if (find_num == 1) {
		stringstream ss;
		//��ȡ��������
		int res_num = 0;
		ss << sub_string;
		ss >> res_num;
		res = res + res_num + 1;
	}
	else if (find_num > 1) res += exp10(size - 1);
	//find_num == 0 �����������������
	//������漸λ
	res += (exp10(size - 2) * (size - 1) * find_num);
	//ʣ�¼�λ
	res += find(sub_string);
	return res;
}
int exp10(int size) {
	int base = 1;
	if (size == 0) return base;
	while (size-- > 0) base = base * 10;
	return base;
}
