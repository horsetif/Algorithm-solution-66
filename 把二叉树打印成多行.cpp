/*
��Ŀ����
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�



˼·�����ڶ��������ӡ��������ҡ�ÿ��������ٵ�ǰֵ��ÿ�����������nextֵ��
�����ǰֵΪ0����ô��ӡһ�㡣Ȼ��nextֵ��ɵ�ǰֵ��
*/

vector<vector<int>> Print(TreeNode* pRoot) {
	vector<vector<int>> ans;
	vector<int> res;
	if (!pRoot) return ans;
	queue<TreeNode*> que;
	int cur = 1, next = 0;
	que.push(pRoot);
	while (!que.empty()) {
		//�������ݣ�ͬʱ��С��ǰֵ
		TreeNode* tmp = que.front();
		que.pop();
		cur--;
		res.push_back(tmp->val);
		if (tmp->left) {
			que.push(tmp->left);
			next++;
		}
		if (tmp->right) {
			que.push(tmp->right);
			next++;
		}
		if (cur == 0) {
			ans.push_back(res);
			res.clear();
			cur = next;
			next = 0;
		}
	}
	return ans;
}