/*
��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��



˼·�����������������ȷ����������λ�á�ͬʱ����������ָ���ʾ����ķ������ӡ�
��������ָ���ʾ������������ӡ�
*/

TreeNode* Convert(TreeNode* pRootOfTree) {
	if (!pRootOfTree) return NULL;
	TreeNode* pre = NULL;
	find(pRootOfTree, &pre);
	//һֱ����飬ֱ���ҵ���һ��
	TreeNode* res = pRootOfTree;
	while (res->left) {
		res = res->left;
	}
	return res;
}
void find(TreeNode* root, TreeNode** pre) {
	if (!root) return;
	//pre����˼����һ��ָ�룬����ʹ���������
	if (root->left)//�Ȳ����,ͬʱ����preֵ
		find(root->left, pre);
	if (*pre) {//preֵ����һ����right��Ϊroot��root����һ��(left)Ϊpre
		(*pre)->right = root;
	}
	root->left = (*pre);
	*pre = root;
	if (root->right)//�����ұ�
		find(root->right, pre);
}