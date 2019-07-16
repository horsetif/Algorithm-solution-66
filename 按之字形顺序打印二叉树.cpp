/*
题目描述
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。


思路：双端队列。or，设置两个栈。一个栈先放左后放右。一个栈先放右后放左。
一定要注意为空操作。
*/

vector<vector<int>> Print(TreeNode* pRoot) {
	vector<vector<int>> ans;
	vector<int> res;
	if (!pRoot) return ans;
	stack<TreeNode*> st[2];
	int cur = 0;//当前栈
	st[0].push(pRoot);
	while (!st[cur].empty()) {
		TreeNode* tmp = st[cur].top();
		st[cur].pop();
		res.push_back(tmp->val);
		if (cur == 0) {//应该先右后左
			if (tmp->left) st[1 - cur].push(tmp->left);
			if (tmp->right) st[1 - cur].push(tmp->right);
		}
		else {
			if (tmp->right) st[1 - cur].push(tmp->right);
			if (tmp->left) st[1 - cur].push(tmp->left);
		}
		//如果是空了，就转换栈
		if (st[cur].empty()) {
			ans.push_back(res);
			res.clear();
			cur = 1 - cur;
		}
	}
	return ans;
}