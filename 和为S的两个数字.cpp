/*
��Ŀ����
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������


˼·�����ֲ��ҡ��̶�һ�����֣�Ȼ���������в�������һ�����ؼ���δ����ظ���
����һ���뷨�����ÿ����ظ�����������ָ��index1= 0,index2 =n-1.
����ʹ���target����ôindex2--.�����С��target����ôindex1++.ֱ������������
*/

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	int n = array.size();
	int start = 0, end = n - 1;
	vector<int> ans;
	while (start < end) {
		//���Ŀ���ֵС��sum����ôstart++������end++��
		int target = array[start] + array[end];
		if (target < sum) start++;
		else if (target > sum) end--;
		else {//�����ͬ����ô���˻��Ƿ���С��
			if (ans.empty() || array[start] * array[end] < ans[0] * ans[1]) {
				ans.push_back(array[start]);
				ans.push_back(array[end]);
			}
			start++;
		}
	}
	return ans;
}