/*
��Ŀ����
����һ��������ת��������������ı�ͷ��



˼·������һ����ָ��p�����ٿռ䣬Ȼ��ָ��head��headָ�벻�䡣head�����ָ����һ��ǰ������С�
*/

ListNode* ReverseList(ListNode* pHead) {
	//�����¿ռ�
	ListNode* new_head = new ListNode(0);
	new_head->next = pHead;
	while (pHead && pHead->next) {
		ListNode* p = pHead->next;//Ҫ�����ָ��λ��
		ListNode* q = new_head->next;//Ҫ����ļ�϶�����λ��
		pHead->next = pHead->next->next;//ɾ������
		new_head->next = p;//�������
		p->next = q;
	}
	return new_head->next;
}