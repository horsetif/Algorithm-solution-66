/*
题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8)中，按结点数值大小顺序第三小结点的值为4。



思路：利用中序遍历。
*/

TreeNode* KthNode(TreeNode* pRoot, int k) {
	if (!pRoot) return NULL;
	//我们需要在遍历的同时，观察k的值，如果没有到达k，那么就一直返回NULL。
	return find(pRoot, k);
}
TreeNode* find(TreeNode* root, int &k) {
	//中序遍历，如果k值为0，那么就返回root节点。否则一直返回空。
	if (!root) return NULL;
	TreeNode* tmp = find(root->left, k);
	//如果返回不是空，那么说明k值已经查到了，就没有必要查了。
	if (tmp) return tmp;
	k--;
	if (k == 0) return root;
	return find(root->right, k);
}