/*
��Ŀ����
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣
���磬 ��5��3��7��2��4��6��8)�У��������ֵ��С˳�����С����ֵΪ4��



˼·���������������
*/

TreeNode* KthNode(TreeNode* pRoot, int k) {
	if (!pRoot) return NULL;
	//������Ҫ�ڱ�����ͬʱ���۲�k��ֵ�����û�е���k����ô��һֱ����NULL��
	return find(pRoot, k);
}
TreeNode* find(TreeNode* root, int &k) {
	//������������kֵΪ0����ô�ͷ���root�ڵ㡣����һֱ���ؿա�
	if (!root) return NULL;
	TreeNode* tmp = find(root->left, k);
	//������ز��ǿգ���ô˵��kֵ�Ѿ��鵽�ˣ���û�б�Ҫ���ˡ�
	if (tmp) return tmp;
	k--;
	if (k == 0) return root;
	return find(root->right, k);
}