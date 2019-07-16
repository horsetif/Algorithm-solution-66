/*
��Ŀ����
��ʵ�������������ֱ��������л��ͷ����л�������


˼·��ֱ�����������Ȼ����һ���ַ�����
*/

TreeNode* decode(char* &str) {
	if (*str == '#') {
		str++; return NULL;
	}
	//��ȡval��numֵ
	int num = 0;
	while (*str != ',')
		num = num * 10 + (*(str++) - '0');
	str++;
	TreeNode* root = new TreeNode(num);
	root->left = decode(str);
	root->right = decode(str);
	return root;
}
char* Serialize(TreeNode *root) {
	//����ǿգ���ô�ͷ���#
	if (!root) return "#";
	//valֵ������һ��
	string num = to_string(root->val);
	num.push_back(',');
	//�������
	char *left = Serialize(root->left);
	char *right = Serialize(root->right);
	char *res = new char[strlen(left) + strlen(right) + num.size()];
	strcpy(res, num.c_str());
	strcat(res, left);
	strcat(res, right);
	return res;
}
TreeNode* Deserialize(char *str) {
	return decode(str);
}