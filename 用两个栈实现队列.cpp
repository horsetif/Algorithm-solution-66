/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。


思路：设置两个栈。一个输入栈，一个输出栈。在输入队列的时候，直接添加到输入栈中。在输出队列的时候，然后输出栈有东西，就从输出栈输出。
如果输出栈没有东西，就把输入栈中所有的东西都添加进去。
*/

public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		//如果输出栈有东西，那么就直接输出
		if (!stack2.empty()) {
			int res = stack2.top();
			stack2.pop();
			return res;
		}
		//如果是空的，就把输入栈中的内容全部导入到输出栈中
		else {
			//导入
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			//输出
			int res = stack2.top();
			stack2.pop();
			return res;
		}
	}

private:
	stack<int> stack1;//输入栈
	stack<int> stack2;//输出栈
};