/*
��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�


˼·��
�������һ������ͷ��С����߲��֣�С���ұ߲��֡� �������һ�����㣬�����Ҳ��֡����ҵ�������Ȼ��鵽��ߺ��ұߡ��ݹ��ؽ���
*/

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	int M = pre.size(), N = vin.size();//���ֱ���������ܳ���
	if (M != N) return NULL;
	return find(pre, vin, 0, M - 1, 0, N - 1);
}
//���ݲ�ͬ�������ؽ�
TreeNode* find(vector<int> &pre, vector<int> &vin, int p_begin, int p_end, int v_begin, int v_end) {
	if (p_begin > p_end || v_begin > v_end) return NULL;
	TreeNode* head = new TreeNode(pre[p_begin]);//�½����ڵ�
	//��������������ڵ�����������е�λ��
	int index = v_begin;
	for (int i = v_begin; i <= v_end; i++)
		if (vin[i] == pre[p_begin]) {
			index = i; break;
		}
	int len_left_tree = index - v_begin; //�������ĳ���
	head->left = find(pre, vin, p_begin + 1, p_begin + len_left_tree, v_begin, index - 1);
	head->right = find(pre, vin, p_begin + len_left_tree + 1, p_end, index + 1, v_end);
	return head;
}
