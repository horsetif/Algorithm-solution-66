/*
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。



思路：放在队列里面打印。先左后右。每次输出减少当前值，每次入队列增加next值。
如果当前值为0，那么打印一层。然后next值变成当前值。
*/

vector<vector<int>> Print(TreeNode* pRoot) {
	vector<vector<int>> ans;
	vector<int> res;
	if (!pRoot) return ans;
	queue<TreeNode*> que;
	int cur = 1, next = 0;
	que.push(pRoot);
	while (!que.empty()) {
		//弹出内容，同时减小当前值
		TreeNode* tmp = que.front();
		que.pop();
		cur--;
		res.push_back(tmp->val);
		if (tmp->left) {
			que.push(tmp->left);
			next++;
		}
		if (tmp->right) {
			que.push(tmp->right);
			next++;
		}
		if (cur == 0) {
			ans.push_back(res);
			res.clear();
			cur = next;
			next = 0;
		}
	}
	return ans;
}