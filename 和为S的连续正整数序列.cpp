/*
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序


思路：设置连续数字 1,2. 如果和小于目标值，那么就往后添加。如果和大于目标值，就前面收缩。
如果就是目标值，就添加结果。且前面往后添加。连续数字的最后一个最大值为目标值的一半。
*/


vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> ans;
	int start = 1, end = 2, target = 3;
	while (start <= sum / 2) {//如果start 大于sum的一半，那么target必定大于sum
		if (target < sum) {//数组整体往后加1
			end++; target += end;
		}
		else if (target > sum) {//数组收缩一位
			start++; target -= (start - 1);
		}
		else {//添加结果，并且整体往后移动一位
			vector<int> tmp;
			for (int i = start; i <= end; i++) tmp.push_back(i);
			ans.push_back(tmp);
			end++; start++;
			target = target + end - (start - 1);
		}
	}
	return ans;
}