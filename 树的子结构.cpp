/*
��Ŀ����
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��


˼·������������A�����A�Ľڵ��B�ĸ��ڵ��غϣ���ô�Ϳ�ʼ���ҡ�����ͬ��������������ҡ�
*/


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot1 || !pRoot2) return false;
	bool res = false;
	if (pRoot1->val == pRoot2->val) res = find(pRoot1, pRoot2);//�غ��˾Ϳ�ʼ����
	if (res) return true;
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}
//���Һ���
bool find(TreeNode* p1, TreeNode* p2) {
	if (!p2) return true;//p2Ϊ�գ�˵���Ѿ�������
	if (!p1) return false; //p1Ϊ�գ�p2��Ϊ�գ�˵���鲻��ȥ��
	if (p1->val != p2->val) return false;
	return find(p1->left, p2->left) && find(p1->right, p2->right);
}