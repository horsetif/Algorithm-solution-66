/*
��Ŀ����
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�



˼·���ԳƲ��ҡ���Ҫ�ǵ�һ�����ڵ���ѵ��������ڵ㡣
*/

bool isSymmetrical(TreeNode* pRoot) {
	if (!pRoot) return true;
	return find(pRoot->left, pRoot->right);
}
bool find(TreeNode* left, TreeNode* right) {
	//���ǿգ���ô�ǿ��Ե�
	if (!left && !right) return true;
	if (!left || !right) return false;//��һ�����ǿգ��Ͳ���
	if (left->val != right->val) return false;//����ֵ��һ�£�˵�����Գ�
	//�ԳƲ���
	return find(left->left, right->right) && find(left->right, right->left);
}