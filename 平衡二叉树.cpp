/*
��Ŀ����
����һ�ö��������жϸö������Ƿ���ƽ���������



˼·��ͬ���Ǻ����������Ҫһ���������ж�ÿһ���ڵ����ȡ�
���Һ��ӵ���Ȳ�ͬ����ô��˵������ƽ��ġ�
ͬ��������Ⱥ��Ƿ�Ϊƽ�⡣
*/

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (!pRoot) return true;
	bool is_balance = true;
	//������ȵ�ͬʱ�����Ƿ�ƽ��
	get_depth(pRoot, is_balance);
	return is_balance;
}
int get_depth(TreeNode* root, bool &is_balance) {
	if (!is_balance) return 0;
	//�սڵ㣬ֱ�ӷ���0
	if (!root) return 0;
	//Ҷ�ӽڵ�
	if (!root->left && !root->right) return 1;
	//�������������
	int left = get_depth(root->left, is_balance);
	if (!is_balance) return 0;
	//�������������
	int right = get_depth(root->right, is_balance);
	if (!is_balance) return 0;
	//��Ȳ�һ�£���ƽ��
	if (abs(left - right) > 1) {
		is_balance = false;
		return 0;
	}
	return max(left, right) + 1;
}
