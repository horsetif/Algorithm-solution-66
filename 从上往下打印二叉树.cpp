/*
��Ŀ����
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��



˼·����һ�����������档
*/

vector<int> PrintFromTopToBottom(TreeNode* root) {
	queue<TreeNode*> que;
	vector<int> ans;
	if (root == NULL) return ans;
	que.push(root);
	while (!que.empty()) {
		TreeNode* tmp = que.front();
		que.pop();
		ans.push_back(tmp->val);//�������ֵ
		//������Ҽ�����оͿ���
		if (tmp->left)
			que.push(tmp->left);
		if (tmp->right)
			que.push(tmp->right);
	}
	return ans;
}