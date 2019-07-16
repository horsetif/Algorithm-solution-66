/*
题目描述
给定一个二叉树和其中的一个结点，
请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。


思路：如果节点有右子树，那么输出的就是右子树的最左边孩子。
如果节点没有右子树。那么往上找。如果他是父亲的左孩子，那么就输出父亲。
如果他是父亲的右孩子，那么继续往上找。如果找到头了，就输出NULL。
*/

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
	if (!pNode) return NULL;
	//如果有右孩子，那么就是右孩子的最左输出.
	TreeLinkNode* res;
	if (pNode->right) {
		res = pNode->right;
		while (res->left) res = res->left;
		return res;
	}
	//否则往上找.知道父亲节点的左孩子是要查找节点
	res = pNode->next;//父亲节点
	while (res && res->left != pNode) {
		pNode = res;
		res = res->next;//更新父亲节点和孩子节点
	}
	return res;
}