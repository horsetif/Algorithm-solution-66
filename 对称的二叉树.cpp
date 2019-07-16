/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。



思路：对称查找。主要是第一个根节点分裂到两个根节点。
*/

bool isSymmetrical(TreeNode* pRoot) {
	if (!pRoot) return true;
	return find(pRoot->left, pRoot->right);
}
bool find(TreeNode* left, TreeNode* right) {
	//都是空，那么是可以的
	if (!left && !right) return true;
	if (!left || !right) return false;//有一个不是空，就不行
	if (left->val != right->val) return false;//两点值不一致，说明不对称
	//对称查找
	return find(left->left, right->right) && find(left->right, right->left);
}