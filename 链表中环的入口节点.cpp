/*
��Ŀ����
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��



˼·�����ÿ���ָ�롣����ָ�뵽��һ�������ڵ�ΪM�������ڵ㵽��ڽڵ�ΪN����ڽڵ㵽�����ڵ�ΪX��
��M+N+X = 2 * M, �� M = N + X. M - X = N. ��ô������ָ��һ����ͷ��һ���������ڵ��������������
����ڵ㡣
*/

ListNode* EntryNodeOfLoop(ListNode* pHead) {
	if (pHead == NULL) return NULL;
	ListNode* slow = pHead, *fast = pHead;
	//���ҿ���ָ���һ�������Ľڵ�
	do {
		slow = slow->next;
		fast = fast->next;
		//�����û�л�
		if (fast && slow) fast = fast->next;
		else return NULL;
	} while (fast != slow);
	//�ڶ��β���,�ҵ�������
	slow = pHead;
	while (slow != fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}