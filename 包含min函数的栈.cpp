/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。



思路：定义一个新栈，专门包含栈中的最小元素。
如果加入一个新元素比最小栈的栈顶元素小，那么就直接加入新元素。
如果加入的新元素比最小栈的栈顶元素大，那么就重复加入栈顶元素。
*/

stack<int> data;
stack<int> data_min;
void push(int value) {
	data.push(value);
	if (data_min.empty()) {
		data_min.push(value);
	}
	else {
		//就看添加的元素是不是比栈顶元素小，小就直接添加。大就重复添加。
		int tmp = data_min.top();
		if (value > tmp) data_min.push(tmp);
		else data_min.push(value);
	}
}
void pop() {
	data.pop();
	data_min.pop();
}
int top() {
	return data.top();
}
int min() {
	return data_min.top();
}