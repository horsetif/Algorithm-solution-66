/*
��Ŀ����
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����


˼·��f(1) = 1 �����ţ�
	  f(2) = 2 (�������ᣩ
	  f(3) = f(1) + f(2)
	  f(4) = f(3) + f(2) (ֻ��ͷ������
	  ˵������쳲��������е����⡣
*/

int rectCover(int number) {
	int step1 = 0, step2 = 1;//��ʼ״̬
	int res;
	if (number <= 0) return 0;
	while (number-- > 0) {
		res = step1 + step2;//���½��
		step1 = step2;
		step2 = res;
	}
	return res;
}