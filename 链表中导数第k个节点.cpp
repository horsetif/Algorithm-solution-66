/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。


思路：先让一个节点向前走k-1步，固定住。然后再设置一个节点从头走
（那个固定住的节点同步走，直到固定节点到达尾部），那么新设置的节点值就是倒数第k个节点。
*/

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (k <= 0 || pListHead == NULL) return NULL;
	ListNode* rear = pListHead, *res = pListHead;
	//rear 指针向后移动k-1步
	while (--k > 0) {
		if (rear == NULL) return NULL;
		rear = rear->next;
	}
	if (rear == NULL) return NULL;
	//整体后移，直到rear指针到达结尾
	while (rear->next != NULL) {
		rear = rear->next;
		res = res->next;
	}
	return res;
}