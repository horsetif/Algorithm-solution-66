/*
��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
��������:
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��


˼·���ܵ��͵Ļ��ݷ�������Ҫע���ظ��ַ������⣬��������Ҫ��������������ظ��ַ������������ظ���ֻ���Ǽ���һ�Σ�
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
	if (index == str.size()) {//�Ѿ��ﵽ��󣬲���Ҫ�ٲ���
		ans.push_back(str);
		return;
	}
	find(str, index + 1);//����������һ��
	//�����󣬲�����һ��
	for (int i = index + 1; i < str.size(); i++) {
		if (str[i] == str[index]) continue;
		swap(str[i], str[index]);
		find(str, index + 1);
		swap(str[i], str[index]);
	}
}