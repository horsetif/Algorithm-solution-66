/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。




思路：一定要满足最后一个数字小于前面一部分数字，大于后面一部分数字。
*/


bool VerifySquenceOfBST(vector<int> sequence) {
	int n = sequence.size();
	if (n == 0) return false;
	return find(sequence, 0, n - 1);//查看开始位置和结束位置之间是不是后序遍历
}
bool find(vector<int> &q, int start, int end) {
	if (end - start < 2) return true;//长度小于等于2的树是一定满足的
	int index = start;
	//查询左子树长度
	while (index < end && q[index] < q[end]) {
		index++;
	}
	//查询右子树长度
	int right_index = index;
	while (right_index < end && q[right_index] >= q[end]) {
		right_index++;
	}
	//如果查完正好，说明又可以成为二叉搜索树
	if (right_index == end) {
		return find(q, start, index - 1) && find(q, index, end - 1);
	}
	else return false;
}