/*
��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�



˼·�����Ƹ���������Ϊ�����ߡ�
��һ����ÿһ��node���棬������node��
�ڶ�������������ָ�롣
��������������
*/

RandomListNode* Clone(RandomListNode* pHead) {
	if (pHead == NULL) return NULL;
	//��һ��������ÿһ���ڵ������ӽڵ�
	RandomListNode* head = pHead;
	while (head != NULL) {
		RandomListNode* tmp = new RandomListNode(head->label);
		tmp->next = head->next;//����ָ����뵽head �� head����ָ��֮��
		head->next = tmp;
		head = tmp->next;//����head�ڵ�
	}
	//�ڶ���������randomָ��
	head = pHead;
	while (head != NULL) {
		RandomListNode* tmp = head->random;
		if (tmp != NULL)//ע�ⲻ��Ϊ��
			head->next->random = tmp->next;//����µ�random����
		head = head->next;
		head = head->next;//����headָ��
	}
	//������������
	head = pHead;
	RandomListNode* res = pHead; res = res->next;
	RandomListNode* tmp = pHead;  tmp = tmp->next;
	while (head != NULL) {
		head->next = tmp->next;
		head = head->next;//����headֵ
		if (head != NULL) {//������滹��ֵ����ô����tmpֵ
			tmp->next = head->next;
			tmp = tmp->next;
		}
		else tmp->next = NULL;
	}
	return res;
}