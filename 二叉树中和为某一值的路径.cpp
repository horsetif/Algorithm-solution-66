/*
题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)



思路：回溯遍历法。通过先序遍历法。注意，这里必须到达叶子节点。否则不行。
*/


vector<vector<int>> ans;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<int> cur; // 当前值
	find(root, expectNumber, cur);
	return ans;
}
void find(TreeNode* root, int p, vector<int> &cur) {
	if (!root) return;
	cur.push_back(root->val);//添加当前搜索值
	p = p - root->val;
	//到达叶子节点，而且正好把数字用完
	if (p == 0 && root->left == root->right) {
		ans.push_back(cur);
		return;
	}
	if (root->left) {
		find(root->left, p, cur);//向左边搜索，搜索完了要弹出，再搜索右边
		cur.pop_back();
	}
	if (root->right) {
		find(root->right, p, cur);
		cur.pop_back();
	}
	return;
}