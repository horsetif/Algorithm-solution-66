/*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。



思路：最好的方法是使用函数栈。不会破坏指针
*/

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> ans;//输出结果
	find(head, ans);//设置函数栈
	return ans;
}
void find(ListNode* head, vector<int> &ans) {
	if (head == NULL) return;
	find(head->next, ans);//先找到头，然后再在退出的时候，把结果添加进去。
	ans.push_back(head->val);
}