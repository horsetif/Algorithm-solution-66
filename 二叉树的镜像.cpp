/*
��Ŀ����
���������Ķ�����������任ΪԴ�������ľ���
��������:
�������ľ����壺Դ������
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		���������
			8
		   /  \
		  10   6
		 / \  / \
		11 9 7  5



˼·��������ֵ��Ȼ���������
*/

void Mirror(TreeNode *pRoot) {
	if (!pRoot) return; //û��˵���Ѿ�������
	TreeNode* left = pRoot->left, *right = pRoot->right;
	pRoot->left = right; pRoot->right = left;//ָ�뽻������
	Mirror(pRoot->left); Mirror(pRoot->right);//��������
	return;
}