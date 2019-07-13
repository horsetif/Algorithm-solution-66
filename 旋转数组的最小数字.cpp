/*
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��


˼·�����ֲ��ҡ���ͣ����������num[start] >= num[end]��˵���յ㻹���������档����˵���յ��Ѿ������������ˡ�
	  �� num[mid] > num[start], ˵�� ��������������ģ�Ӧ�ü���ұߡ���ô start = mid;
	  �� num[mid] <= num[end], ˵�������ұ�������ģ�Ӧ�ü����ߡ���ô end = mid;
	  ��һ�������������num[start] >= num[end] ��ʱ�����ǵĳ����Ѿ�ֻ��2�ˣ���ô���ǽ���ģ���ô������Сֵ����num[end].
*/

int minNumberInRotateArray(vector<int> rotateArray) {
	int n = rotateArray.size();
	if (n == 0) return 0;
	if (n == 1) return rotateArray[0];
	int start = 0, end = n - 1, mid = (start + end) / 2;//��������ָ��
	while (rotateArray[start] >= rotateArray[end]) {//˵���������黹��������
		if (end - start == 1) {
			mid = end; break; //ֻ�����������ˣ�û�м���Ҫ�ˡ�
		}
		mid = (start + end) / 2;
		//˵�����������ô�ͼ���ұ�
		if (rotateArray[mid] >= rotateArray[start]) start = mid;
		//˵���ұ�������ô�ͼ�����
		else end = mid;
	}
	return rotateArray[mid];
}