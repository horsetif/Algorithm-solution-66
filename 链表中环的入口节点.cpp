/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。



思路：设置快慢指针。设慢指针到第一次相遇节点为M。相遇节点到入口节点为N。入口节点到相遇节点为X。
则：M+N+X = 2 * M, 则 M = N + X. M - X = N. 那么两个慢指针一个从头，一个从相遇节点出发，相遇就是
交叉节点。
*/

ListNode* EntryNodeOfLoop(ListNode* pHead) {
	if (pHead == NULL) return NULL;
	ListNode* slow = pHead, *fast = pHead;
	//查找快慢指针第一次相遇的节点
	do {
		slow = slow->next;
		fast = fast->next;
		//检测有没有环
		if (fast && slow) fast = fast->next;
		else return NULL;
	} while (fast != slow);
	//第二次查找,找到相遇点
	slow = pHead;
	while (slow != fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}