/*
��Ŀ����
����һ�������������е�һ����㣬
���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣


˼·������ڵ�������������ô����ľ���������������ߺ��ӡ�
����ڵ�û������������ô�����ҡ�������Ǹ��׵����ӣ���ô��������ס�
������Ǹ��׵��Һ��ӣ���ô���������ҡ�����ҵ�ͷ�ˣ������NULL��
*/

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
	if (!pNode) return NULL;
	//������Һ��ӣ���ô�����Һ��ӵ��������.
	TreeLinkNode* res;
	if (pNode->right) {
		res = pNode->right;
		while (res->left) res = res->left;
		return res;
	}
	//����������.֪�����׽ڵ��������Ҫ���ҽڵ�
	res = pNode->next;//���׽ڵ�
	while (res && res->left != pNode) {
		pNode = res;
		res = res->next;//���¸��׽ڵ�ͺ��ӽڵ�
	}
	return res;
}