/*
��Ŀ����
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���


˼·������������������η�����2�ı�����a^(2*n) =  (a^n) * (a^n) . or  a^(2*n+1) = a^n * a^n * a
������Ҫ�������a�Ǹ�����������Ѿ�n�Ǹ����������

*/
double Power(double base, int exponent) {
	//��������
	if (base == 0) return 0;
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	bool base_flag = false, exponent_flag = false;
	//��Ը���������
	if (base < 0) {
		base_flag = true;
		base = -1 * base;
	}
	if (exponent < 0) {
		exponent_flag = true;
		exponent = -1 * exponent;
	}
	//����Ӧ�ö�������������
	double res = Power(base, exponent / 2);
	if (exponent % 2 == 0) res = res * res;
	else res = res * res * base;
	//��������������Ǹ�������ָ������������ô���Ӧ���Ǹ���
	if (base_flag && exponent % 2 != 0) res = -1 * res;
	//�������ָ���Ǹ�������ô���Ӧ���ǵ���
	if (exponent_flag) res = 1 / res;
	return res;
}
