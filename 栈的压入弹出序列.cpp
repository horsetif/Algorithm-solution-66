/*
��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
����4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�



˼·����ȫģ��ջ��˼��Ϳ��ԡ������������û����ջ���ϣ���ô�Ͳ�ͣѹ�롣ֱ��ջ��Ԫ���е������֡�Ȼ�󵯳���
���ջ�ǲ��ǿյģ����ߵ���������û�е������
*/

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	int n = pushV.size();
	stack<int> st;//��ʱ�Ĳ���ջ
	int push_ind = 0, pop_ind = 0;//��ǰָ��
	while (pop_ind < n) {//��ͣ��ⵯ������
		if (st.empty()) {
			if (push_ind < n) st.push(pushV[push_ind++]);//��ӵ�ջ��
			else return false; //һֱû���ҵ�
		}
		//���ջ��һֱ����Ҫ�ҵ�ֵ����ô�Ͳ�ͣ��ջ
		while (st.top() != popV[pop_ind]) {
			if (push_ind < n) st.push(pushV[push_ind++]);
			else return false;
		}
		st.pop();
		pop_ind++;
	}
	return true;
}