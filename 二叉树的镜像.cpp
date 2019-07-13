/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		镜像二叉树
			8
		   /  \
		  10   6
		 / \  / \
		11 9 7  5



思路：交换数值，然后遍历查找
*/

void Mirror(TreeNode *pRoot) {
	if (!pRoot) return; //没有说明已经查完了
	TreeNode* left = pRoot->left, *right = pRoot->right;
	pRoot->left = right; pRoot->right = left;//指针交换操作
	Mirror(pRoot->left); Mirror(pRoot->right);//遍历操作
	return;
}