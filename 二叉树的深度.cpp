/*
题目描述
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。


思路：类似后序遍历。先找到叶子节点的深度。然后往上找。每次更新得到最大值。
*/


int TreeDepth(TreeNode* pRoot) {
	if (!pRoot) return 0;
	//叶子节点
	if (!pRoot->left && !pRoot->right) return 1;
	//找到两个叶子节点的深度
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	//更新当前节点深度
	return 1 + max(left, right);
}

