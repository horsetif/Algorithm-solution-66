/*
��Ŀ����
����һ����������������е�����k����㡣


˼·������һ���ڵ���ǰ��k-1�����̶�ס��Ȼ��������һ���ڵ��ͷ��
���Ǹ��̶�ס�Ľڵ�ͬ���ߣ�ֱ���̶��ڵ㵽��β��������ô�����õĽڵ�ֵ���ǵ�����k���ڵ㡣
*/

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (k <= 0 || pListHead == NULL) return NULL;
	ListNode* rear = pListHead, *res = pListHead;
	//rear ָ������ƶ�k-1��
	while (--k > 0) {
		if (rear == NULL) return NULL;
		rear = rear->next;
	}
	if (rear == NULL) return NULL;
	//������ƣ�ֱ��rearָ�뵽���β
	while (rear->next != NULL) {
		rear = rear->next;
		res = res->next;
	}
	return res;
}