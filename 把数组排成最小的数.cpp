/*
��Ŀ����
����һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��



˼·�������ַ���������㣬�����ǰ�����������Ӧ���ַ������ֵ������ܡ�
*/

string PrintMinNumber(vector<int> numbers) {
	vector<string> ans;
	//ת��Ϊ�ַ���
	for (auto num : numbers) {
		ans.push_back(to_string(num));
	}
	//�µıȽϷ���
	sort(ans.begin(), ans.end(), cmp());
	string res;
	for (auto a : ans) res = res + a;
	return res;
}
struct cmp {
	bool operator()(string a, string b) {
		//�����������У����ָ���С
		string A = a + b, B = b + a;
		return A < B;
	}
};