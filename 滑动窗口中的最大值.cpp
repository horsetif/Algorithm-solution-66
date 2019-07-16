/*
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。


思路：同样是最大栈的思想。设置一个队列。没有加入一个值，如果这个值比队列中最后一个值
大，那么队列的最后一个值弹出。保证每次弹出的都是最大值。
同时每次还有基于距离进行更新，距离太远（查过窗口范围的，也要删除。
*/

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	vector<int> ans;//返回值
	deque<int> que;//设置双边队列
	int n = num.size();
	if (n < size || size < 1) return ans;
	if (size == 1) return num;
	int index = 0;
	//初始化窗口
	while (index < size) {
		while (!que.empty() && num[que.back()] <= num[index])
			que.pop_back();
		que.push_back(index);
		index++;
	}
	while (index < n) {
		ans.push_back(num[que.front()]);//这是要弹出的值
		//如果很大，可以不断从末尾弹出
		while (!que.empty() && num[que.back()] <= num[index])
			que.pop_back();
		//去除距离过于远的值
		while (!que.empty() && index - que.front() >= size)
			que.pop_front();
		que.push_back(index);
		index++;
	}
	ans.push_back(num[que.front()]);
	return ans;
}