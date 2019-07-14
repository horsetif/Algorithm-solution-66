/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。


思路：很典型的回溯法。但是要注意重复字符的问题，所以我们要先排序。如果遇到重复字符就跳过。（重复的只考虑计算一次）
*/


vector<string> ans;
vector<string> Permutation(string str) {
	if (str.size() == 0) return ans;
	sort(str.begin(), str.end());
	int n = str.size();
	find(str, 0);
	sort(ans.begin(), ans.end());
	return ans;
}
void find(string str, int index) {
	if (index == str.size()) {//已经达到最后，不需要再查了
		ans.push_back(str);
		return;
	}
	find(str, index + 1);//单纯查找下一个
	//交换后，查找下一个
	for (int i = index + 1; i < str.size(); i++) {
		if (str[i] == str[index]) continue;
		swap(str[i], str[index]);
		find(str, index + 1);
		swap(str[i], str[index]);
	}
}