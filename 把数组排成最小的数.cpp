/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。



思路：按照字符串排序计算，而不是按照数字排序。应该字符串有字典排序功能。
*/

string PrintMinNumber(vector<int> numbers) {
	vector<string> ans;
	//转化为字符串
	for (auto num : numbers) {
		ans.push_back(to_string(num));
	}
	//新的比较方法
	sort(ans.begin(), ans.end(), cmp());
	string res;
	for (auto a : ans) res = res + a;
	return res;
}
struct cmp {
	bool operator()(string a, string b) {
		//看这两种排列，那种更加小
		string A = a + b, B = b + a;
		return A < B;
	}
};