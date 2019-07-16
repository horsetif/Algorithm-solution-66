/*
题目描述
发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,
想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子....
.LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。
为了方便起见,你可以认为大小王是0。



思路：先排序。计算0的个数。然后从第一个不是0的位置开始顺序遍历。如果中间出现断层，就用0来填。
如果0填完了，还存在断层，那么就返回fasle。如果走完了，那么就可以返回true了。
*/

bool IsContinuous(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
	int zero_num = 0, index = 0, n = numbers.size();//零的个数，非零开始位置
	if (n == 0) return false;
	//计算0的个数，以及第一个非零开始
	for (; index < n; index++) {
		if (numbers[index] != 0) break;
		zero_num++;
	}
	if (index == n) return true;
	index++;
	while (index < n) {
		//计算有多大间隔
		int diff = numbers[index] - numbers[index - 1];
		if (diff == 0) return false;//无间隔，说明不可能是顺子
		zero_num = zero_num - (diff - 1);//补0
		if (zero_num < 0) return false;//补过头了就说明不可能了
		index++;
	}
	return true;
}