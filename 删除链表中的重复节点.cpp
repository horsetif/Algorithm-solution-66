/*
��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5



˼·���ݹ������������ڵ��Ƕ�һ�޶��ģ�����һ���ڵ������ֵ��ͬ������ô�����Ӻ󷵻ء�
�������ڵ㲻�Ƕ�һ�޶��ģ�����ڵ�ֵ������ͬ������ô�͵ݹ鷵��ɾ����ڵ㡣
*/

ListNode* deleteDuplication(ListNode* pHead) {
	if (pHead == NULL) return NULL;
	//����û��ֵ�ˣ���ô��ֱ�ӷ���
	if (!pHead->next) return pHead;
	//�����ظ��ģ����Ӻ�ɾ��
	if (pHead->next->val != pHead->val) {
		pHead->next = deleteDuplication(pHead->next);
		return pHead;
	}
	//���ظ��ģ���ô�Ͳ�������
	else {
		int val = pHead->val;
		//�ҵ���һ������val��ֵ
		while (pHead && pHead->val == val) pHead = pHead->next;
		return deleteDuplication(pHead);
	}
}