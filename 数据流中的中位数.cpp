/*
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。



思路：利用最大堆和最小堆来做。数据前面部分放在最大堆里，后面部分放在最小堆里。
如果两个堆数量相同，那么优先放在最大堆（前面部分）。
如果想要加入最大堆时，那么一定要先进行最小堆排序，然后弹出最大值，加入到最大堆中。
同样，加入最小堆时候，要先进行最大堆排序。然后弹出最大值，把最大值加入到最小堆中。
这样才能保持平衡。
*/

vector<int> max;
vector<int> min;
int tmp;
void Insert(int num) {
	//如果两个堆数量相同，那么优先加入最大堆
	if (max.size() == min.size()) {
		//现在最小堆更新一遍，然后添到最大堆里面
		min.push_back(num);
		push_heap(min.begin(), min.end(), greater<int>());
		tmp = min[0];
		pop_heap(min.begin(), min.end(), greater<int>());
		min.pop_back();
		max.push_back(tmp);
		push_heap(max.begin(), max.end(), less<int>());
	}
	//如果不相同，说明最大堆多了，要添加到最小堆中
	else {//现在最大堆里更新一遍
		max.push_back(num);
		push_heap(max.begin(), max.end(), less<int>());
		tmp = max[0];
		pop_heap(max.begin(), max.end(), less<int>());
		max.pop_back();
		min.push_back(tmp);
		push_heap(min.begin(), min.end(), greater<int>());
	}
}

double GetMedian() {
	//相同就返回中间值，不相同就返回最大堆的值
	if (max.size() == min.size()) {
		int num1 = min[0], num2 = max[0];
		return double(num1 + num2) / 2;
	}
	else {
		return max[0];
	}
}