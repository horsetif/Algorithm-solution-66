/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。



思路：用一个队列来保存。
*/

vector<int> PrintFromTopToBottom(TreeNode* root) {
	queue<TreeNode*> que;
	vector<int> ans;
	if (root == NULL) return ans;
	que.push(root);
	while (!que.empty()) {
		TreeNode* tmp = que.front();
		que.pop();
		ans.push_back(tmp->val);//更新输出值
		//先左后右加入队列就可以
		if (tmp->left)
			que.push(tmp->left);
		if (tmp->right)
			que.push(tmp->right);
	}
	return ans;
}