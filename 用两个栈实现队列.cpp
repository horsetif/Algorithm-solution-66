/*
��Ŀ����
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�


˼·����������ջ��һ������ջ��һ�����ջ����������е�ʱ��ֱ����ӵ�����ջ�С���������е�ʱ��Ȼ�����ջ�ж������ʹ����ջ�����
������ջû�ж������Ͱ�����ջ�����еĶ�������ӽ�ȥ��
*/

public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		//������ջ�ж�������ô��ֱ�����
		if (!stack2.empty()) {
			int res = stack2.top();
			stack2.pop();
			return res;
		}
		//����ǿյģ��Ͱ�����ջ�е�����ȫ�����뵽���ջ��
		else {
			//����
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			//���
			int res = stack2.top();
			stack2.pop();
			return res;
		}
	}

private:
	stack<int> stack1;//����ջ
	stack<int> stack2;//���ջ
};