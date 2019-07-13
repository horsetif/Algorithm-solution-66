/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。


思路：
先序遍历一定满足头，小于左边部分，小于右边部分。 中序遍历一定满足，左中右部分。先找到树根，然后查到左边和右边。递归重建。
*/

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	int M = pre.size(), N = vin.size();//两种遍历情况的总长度
	if (M != N) return NULL;
	return find(pre, vin, 0, M - 1, 0, N - 1);
}
//根据不同部分来重建
TreeNode* find(vector<int> &pre, vector<int> &vin, int p_begin, int p_end, int v_begin, int v_end) {
	if (p_begin > p_end || v_begin > v_end) return NULL;
	TreeNode* head = new TreeNode(pre[p_begin]);//新建根节点
	//查找先序遍历根节点在中序遍历中的位置
	int index = v_begin;
	for (int i = v_begin; i <= v_end; i++)
		if (vin[i] == pre[p_begin]) {
			index = i; break;
		}
	int len_left_tree = index - v_begin; //左子树的长度
	head->left = find(pre, vin, p_begin + 1, p_begin + len_left_tree, v_begin, index - 1);
	head->right = find(pre, vin, p_begin + len_left_tree + 1, p_end, index + 1, v_end);
	return head;
}
