/*
��Ŀ����
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��
�������{2,3,4,2,6,2,5,1}�Ļ�������������6����
{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}��
{2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��


˼·��ͬ�������ջ��˼�롣����һ�����С�û�м���һ��ֵ��������ֵ�ȶ��������һ��ֵ
����ô���е����һ��ֵ��������֤ÿ�ε����Ķ������ֵ��
ͬʱÿ�λ��л��ھ�����и��£�����̫Զ��������ڷ�Χ�ģ�ҲҪɾ����
*/

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	vector<int> ans;//����ֵ
	deque<int> que;//����˫�߶���
	int n = num.size();
	if (n < size || size < 1) return ans;
	if (size == 1) return num;
	int index = 0;
	//��ʼ������
	while (index < size) {
		while (!que.empty() && num[que.back()] <= num[index])
			que.pop_back();
		que.push_back(index);
		index++;
	}
	while (index < n) {
		ans.push_back(num[que.front()]);//����Ҫ������ֵ
		//����ܴ󣬿��Բ��ϴ�ĩβ����
		while (!que.empty() && num[que.back()] <= num[index])
			que.pop_back();
		//ȥ���������Զ��ֵ
		while (!que.empty() && index - que.front() >= size)
			que.pop_front();
		que.push_back(index);
		index++;
	}
	ans.push_back(num[que.front()]);
	return ans;
}