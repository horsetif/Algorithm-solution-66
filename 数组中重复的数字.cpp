/*
��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��



˼·����Ȼ������0 - n-1 ֮�䣬��ô����ÿ�μ��һ�����֣�Ȼ����������ǲ��Ƿ��ڶ�Ӧλ���ϡ�
���Ǿͽ���swap(num[i],num[num[i]]).֪�����ڶԵ�λ�á����Ҫ�������������ڵ���һ������ô˵���ظ��ˡ�
*/

// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
bool duplicate(int numbers[], int length, int* duplication) {
	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {//λ�ò����
			if (numbers[i] == numbers[numbers[i]]) {//��һ��λ����ͬ
				*duplication = numbers[i];
				return true;
			}
			//����
			swap(numbers[i], numbers[numbers[i]]);
		}
	}
	return false;
}