/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。



思路：设置一个新指针p，开辟空间，然后指向head。head指针不变。head后面的指针逐一往前插入就行。
*/

ListNode* ReverseList(ListNode* pHead) {
	//开辟新空间
	ListNode* new_head = new ListNode(0);
	new_head->next = pHead;
	while (pHead && pHead->next) {
		ListNode* p = pHead->next;//要处理的指针位置
		ListNode* q = new_head->next;//要插入的间隙后面的位置
		pHead->next = pHead->next->next;//删除操作
		new_head->next = p;//插入操作
		p->next = q;
	}
	return new_head->next;
}