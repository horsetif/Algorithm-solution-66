/*
��Ŀ����
����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��



˼·����õķ�����ʹ�ú���ջ�������ƻ�ָ��
*/

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> ans;//������
	find(head, ans);//���ú���ջ
	return ans;
}
void find(ListNode* head, vector<int> &ans) {
	if (head == NULL) return;
	find(head->next, ans);//���ҵ�ͷ��Ȼ�������˳���ʱ�򣬰ѽ����ӽ�ȥ��
	ans.push_back(head->val);
}