/*
��Ŀ����
��ʵ��һ����������֮���δ�ӡ��������
����һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ��
�����а��մ����ҵ�˳���ӡ���������Դ����ơ�


˼·��˫�˶��С�or����������ջ��һ��ջ�ȷ������ҡ�һ��ջ�ȷ��Һ����
һ��Ҫע��Ϊ�ղ�����
*/

vector<vector<int>> Print(TreeNode* pRoot) {
	vector<vector<int>> ans;
	vector<int> res;
	if (!pRoot) return ans;
	stack<TreeNode*> st[2];
	int cur = 0;//��ǰջ
	st[0].push(pRoot);
	while (!st[cur].empty()) {
		TreeNode* tmp = st[cur].top();
		st[cur].pop();
		res.push_back(tmp->val);
		if (cur == 0) {//Ӧ�����Һ���
			if (tmp->left) st[1 - cur].push(tmp->left);
			if (tmp->right) st[1 - cur].push(tmp->right);
		}
		else {
			if (tmp->right) st[1 - cur].push(tmp->right);
			if (tmp->left) st[1 - cur].push(tmp->left);
		}
		//����ǿ��ˣ���ת��ջ
		if (st[cur].empty()) {
			ans.push_back(res);
			res.clear();
			cur = 1 - cur;
		}
	}
	return ans;
}