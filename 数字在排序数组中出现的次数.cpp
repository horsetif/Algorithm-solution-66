/*
��Ŀ����
ͳ��һ�����������������г��ֵĴ�����


˼·�����ֲ��ҡ��ҵ����ֵ�����ߣ����ұߡ�Ȼ���һ�¾Ϳ��ԡ�ע����Լ���Ķ��ֲ��ҵĿ��.
*/

int GetNumberOfK(vector<int> data, int k) {
	int index1 = find_first_ind(data, k);
	if (index1 >= 0 && index1 < data.size() && data[index1] == k) {
		int index2 = find_last_ind(data, k);
		return index2 - index1 + 1;
	}
	else return 0;
}
int find_first_ind(vector<int> &data, int k) {
	int start = 0, end = data.size() - 1;
	while (start <= end) {
		//ȡ��λ
		int mid = (start + end) / 2;
		//������ֲ���
		if (data[mid] > k) end = mid - 1;
		else if (data[mid] < k) start = mid + 1;
		else {//����鵽�ˣ���������
			if (mid > 0 && data[mid - 1] == k) end = mid - 1;
			else return mid;
		}
	}
	return start;
}
int find_last_ind(vector<int> &data, int k) {
	int start = 0, end = data.size() - 1;
	while (start <= end) {
		//ȡ��λ
		int mid = (start + end) / 2;
		//������ֲ���
		if (data[mid] > k) end = mid - 1;
		else if (data[mid] < k) start = mid + 1;
		else {//����鵽�ˣ���������
			if (mid < data.size() - 1 && data[mid + 1] == k) start = mid + 1;
			else return mid;
		}
	}
	return start;
}