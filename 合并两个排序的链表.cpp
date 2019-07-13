/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。


思路：设置一个新表头，然后遍历添加即可。
*/

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1) return pHead2;
	if (!pHead2) return pHead1;//有一个链表为空情况
	ListNode* head = new ListNode(0);//设置表头
	ListNode* rear = head;//链表的结尾位置
	while (pHead1 && pHead2) {
		if (pHead1->val < pHead2->val) {//要处理p1 序列
			rear->next = pHead1;//连接操作
			rear = rear->next;
			pHead1 = pHead1->next;//删除操作
			rear->next = NULL;//断开操作
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