/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）



思路：复制复杂链表，分为三步走。
第一步：每一个node后面，插入新node。
第二步：复制特殊指针。
第三步：解锁。
*/

RandomListNode* Clone(RandomListNode* pHead) {
	if (pHead == NULL) return NULL;
	//第一步，链表每一个节点后面添加节点
	RandomListNode* head = pHead;
	while (head != NULL) {
		RandomListNode* tmp = new RandomListNode(head->label);
		tmp->next = head->next;//把新指针插入到head 和 head后面指针之间
		head->next = tmp;
		head = tmp->next;//更新head节点
	}
	//第二步，复制random指针
	head = pHead;
	while (head != NULL) {
		RandomListNode* tmp = head->random;
		if (tmp != NULL)//注意不能为空
			head->next->random = tmp->next;//添加新的random连接
		head = head->next;
		head = head->next;//更新head指针
	}
	//第三步，解耦
	head = pHead;
	RandomListNode* res = pHead; res = res->next;
	RandomListNode* tmp = pHead;  tmp = tmp->next;
	while (head != NULL) {
		head->next = tmp->next;
		head = head->next;//更新head值
		if (head != NULL) {//如果下面还有值，那么更新tmp值
			tmp->next = head->next;
			tmp = tmp->next;
		}
		else tmp->next = NULL;
	}
	return res;
}