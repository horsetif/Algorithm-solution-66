/*
��Ŀ����
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������


˼·������һ���±�ͷ��Ȼ�������Ӽ��ɡ�
*/

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1) return pHead2;
	if (!pHead2) return pHead1;//��һ������Ϊ�����
	ListNode* head = new ListNode(0);//���ñ�ͷ
	ListNode* rear = head;//����Ľ�βλ��
	while (pHead1 && pHead2) {
		if (pHead1->val < pHead2->val) {//Ҫ����p1 ����
			rear->next = pHead1;//���Ӳ���
			rear = rear->next;
			pHead1 = pHead1->next;//ɾ������
			rear->next = NULL;//�Ͽ�����
		}
		else {
			rear->next = pHead2;
			rear = rear->next;
			pHead2 = pHead2->next;
			rear->next = NULL;
		}
	}
	if (pHead1) rear->next = pHead1;
	else if (pHead2) rear->next = pHead2;
	return head->next;
}