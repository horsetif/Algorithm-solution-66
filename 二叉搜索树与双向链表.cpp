/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。



思路：首先是中序遍历，确定二叉树的位置。同时，让树的左指针表示链表的反向链接。
让树的右指针表示链表的正向链接。
*/

TreeNode* Convert(TreeNode* pRootOfTree) {
	if (!pRootOfTree) return NULL;
	TreeNode* pre = NULL;
	find(pRootOfTree, &pre);
	//一直往左查，直到找到第一个
	TreeNode* res = pRootOfTree;
	while (res->left) {
		res = res->left;
	}
	return res;
}
void find(TreeNode* root, TreeNode** pre) {
	if (!root) return;
	//pre的意思的上一个指针，这里使用中序遍历
	if (root->left)//先查左边,同时更新pre值
		find(root->left, pre);
	if (*pre) {//pre值的下一个（right）为root，root的上一个(left)为pre
		(*pre)->right = root;
	}
	root->left = (*pre);
	*pre = root;
	if (root->right)//再连右边
		find(root->right, pre);
}