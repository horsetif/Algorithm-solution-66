/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。



思路：同样是后序遍历。需要一个函数来判断每一个节点的深度。
左右孩子的深度不同，那么就说明不是平衡的。
同步更新深度和是否为平衡。
*/

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (!pRoot) return true;
	bool is_balance = true;
	//更新深度的同时更新是否平衡
	get_depth(pRoot, is_balance);
	return is_balance;
}
int get_depth(TreeNode* root, bool &is_balance) {
	if (!is_balance) return 0;
	//空节点，直接返回0
	if (!root) return 0;
	//叶子节点
	if (!root->left && !root->right) return 1;
	//计算左子树深度
	int left = get_depth(root->left, is_balance);
	if (!is_balance) return 0;
	//计算右子树深度
	int right = get_depth(root->right, is_balance);
	if (!is_balance) return 0;
	//深度不一致，不平衡
	if (abs(left - right) > 1) {
		is_balance = false;
		return 0;
	}
	return max(left, right) + 1;
}
