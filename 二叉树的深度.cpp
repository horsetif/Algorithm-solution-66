/*
��Ŀ����
����һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�


˼·�����ƺ�����������ҵ�Ҷ�ӽڵ����ȡ�Ȼ�������ҡ�ÿ�θ��µõ����ֵ��
*/


int TreeDepth(TreeNode* pRoot) {
	if (!pRoot) return 0;
	//Ҷ�ӽڵ�
	if (!pRoot->left && !pRoot->right) return 1;
	//�ҵ�����Ҷ�ӽڵ�����
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	//���µ�ǰ�ڵ����
	return 1 + max(left, right);
}

