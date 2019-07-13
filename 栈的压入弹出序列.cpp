/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）



思路：完全模仿栈的思想就可以。如果弹出队列没有在栈顶上，那么就不停压入。直到栈顶元素有弹出数字。然后弹出。
最后看栈是不是空的，或者弹出序列有没有到达最后。
*/

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	int n = pushV.size();
	stack<int> st;//暂时的测试栈
	int push_ind = 0, pop_ind = 0;//当前指针
	while (pop_ind < n) {//不停检测弹出序列
		if (st.empty()) {
			if (push_ind < n) st.push(pushV[push_ind++]);//添加到栈中
			else return false; //一直没有找到
		}
		//如果栈顶一直不是要找的值，那么就不停入栈
		while (st.top() != popV[pop_ind]) {
			if (push_ind < n) st.push(pushV[push_ind++]);
			else return false;
		}
		st.pop();
		pop_ind++;
	}
	return true;
}