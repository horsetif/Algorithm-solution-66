/*
��Ŀ����
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�



˼·�����������������Ϊ���ף�������������*2 ��Ϊ��λ��
�������㣬ֱ��û�н�λΪֹ��

*/

int Add(int num1, int num2) {
	int base = 0, carry = 0;
	do {
		base = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = base; num2 = carry;
	} while (num2 != 0);
	return base;
}