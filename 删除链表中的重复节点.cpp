/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5



思路：递归操作。如果这点节点是独一无二的（下面一个节点和他的值不同），那么就连接后返回。
如果这个节点不是独一无二的（下面节点值和他不同），那么就递归返回删除后节点。
*/

ListNode* deleteDuplication(ListNode* pHead) {
	if (pHead == NULL) return NULL;
	//下面没有值了，那么就直接返回
	if (!pHead->next) return pHead;
	//不是重复的，连接后删除
	if (pHead->next->val != pHead->val) {
		pHead->next = deleteDuplication(pHead->next);
		return pHead;
	}
	//是重复的，那么就不连接了
	else {
		int val = pHead->val;
		//找到第一个不是val的值
		while (pHead && pHead->val == val) pHead = pHead->next;
		return deleteDuplication(pHead);
	}
}