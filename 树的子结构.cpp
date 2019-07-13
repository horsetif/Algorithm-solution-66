/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


思路：遍历二叉树A，如果A的节点和B的根节点重合，那么就开始查找。查找同样用先序遍历查找。
*/


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot1 || !pRoot2) return false;
	bool res = false;
	if (pRoot1->val == pRoot2->val) res = find(pRoot1, pRoot2);//重合了就开始查找
	if (res) return true;
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}
//查找函数
bool find(TreeNode* p1, TreeNode* p2) {
	if (!p2) return true;//p2为空，说明已经查完了
	if (!p1) return false; //p1为空，p2不为空，说明查不下去了
	if (p1->val != p2->val) return false;
	return find(p1->left, p2->left) && find(p1->right, p2->right);
}