/*
��Ŀ����
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)



˼·�����ݱ�������ͨ�������������ע�⣬������뵽��Ҷ�ӽڵ㡣�����С�
*/


vector<vector<int>> ans;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<int> cur; // ��ǰֵ
	find(root, expectNumber, cur);
	return ans;
}
void find(TreeNode* root, int p, vector<int> &cur) {
	if (!root) return;
	cur.push_back(root->val);//��ӵ�ǰ����ֵ
	p = p - root->val;
	//����Ҷ�ӽڵ㣬�������ð���������
	if (p == 0 && root->left == root->right) {
		ans.push_back(cur);
		return;
	}
	if (root->left) {
		find(root->left, p, cur);//�������������������Ҫ�������������ұ�
		cur.pop_back();
	}
	if (root->right) {
		find(root->right, p, cur);
		cur.pop_back();
	}
	return;
}