/*
��Ŀ����
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��



˼·���ַ������Ʋ���������ͳ���ַ����еĿո��� n��Ȼ�����ַ��������¿��� 2n�Ŀռ��������������ַ���Ȼ��Ӻ���ǰ������������ǿո���ô�����ƶ�������ǿո���ô���%20���������֡�
	ע���������char*�Ŀռ�ָ�롣
*/

void replaceSpace(char *str, int length) {
	char *head = str;
	int len = 0, space_len = 0;//�����ַ����ȣ��Լ��ո���ܳ��ȡ�
	while (*head != '\0') {
		if (*head == ' ') space_len++;
		len++;
		head++;
	}
	int new_len = len + 2 * space_len;
	str[new_len--] = '\0';//�����ַ����һλ
	len--;
	while (len >= 0) {
		//���ǿո���������ô��ֱ�Ӻ��ƾ���
		if (str[len] != ' ') {
			str[new_len--] = str[len--];
		}
		//�ǿո��������Ͱ������ַ�����ȥ��
		else {
			len--;
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len--] = '%';
		}
	}
}