/*
��Ŀ����
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����


˼·������һ��n*n�ľ������жԽ���Ϊ1.
��������������¾��󡣴�������������Ͼ���������ӿ���ֱ�ӳ˻���
*/

vector<int> multiply(const vector<int>& A) {
	int n = A.size();
	vector<int> ans(n, 1);
	if (n <= 1) return ans;
	int tmp = 1;//��ǰֵ
	for (int i = 1; i < n; i++) {//�������½ǣ����ϵ���
		tmp = tmp * A[i - 1];
		ans[i] = ans[i] * tmp;
	}
	tmp = 1;
	for (int i = n - 2; i >= 0; i--) {//�������Ͻǣ����µ���
		tmp = tmp * A[i + 1];
		ans[i] = ans[i] * tmp;
	}
	return ans;
}