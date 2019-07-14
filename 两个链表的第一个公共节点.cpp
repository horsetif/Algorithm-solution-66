/*
��Ŀ����
�������������ҳ����ǵĵ�һ��������㡣


˼·�����������ཻ֮�󣬾Ͳ����ٷֿ��ˡ���������
����������p1������֮�󣬽���p2�������㡣
ͬ����p2������֮�󣬽���p1�������㡣��һ���ཻ�ĵط������������ҵ�ֵ��
*/

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode* p1 = pHead1, *p2 = pHead2;
	if (!p1 || !p2) return NULL;
	while (p1 != p2) {
		//��������ͬʱ������һ��
		p1 = p1->next;
		p2 = p2->next;
		//��������ͬʱ�ߵ��˿սڵ㣬˵�����е��ǿսڵ�
		if (p1 == p2) return p1;
		//���򽻻�����
		if (!p1) p1 = pHead2;
		if (!p2) p2 = pHead1;

	}
	return p1;
}