/*
题目描述
输入两个链表，找出它们的第一个公共结点。


思路：两个链表相交之后，就不会再分开了。（单链表）
所以我们让p1计算完之后，进入p2继续计算。
同样，p2计算完之后，进入p1继续计算。第一次相交的地方，就是我们找的值。
*/

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode* p1 = pHead1, *p2 = pHead2;
	if (!p1 || !p2) return NULL;
	while (p1 != p2) {
		//两个链表同时往后走一格
		p1 = p1->next;
		p2 = p2->next;
		//两个链表同时走到了空节点，说明共有的是空节点
		if (p1 == p2) return p1;
		//否则交换着走
		if (!p1) p1 = pHead2;
		if (!p2) p2 = pHead1;

	}
	return p1;
}