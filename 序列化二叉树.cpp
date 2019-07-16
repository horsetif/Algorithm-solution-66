/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树


思路：直接先序遍历。然后变成一个字符串。
*/

TreeNode* decode(char* &str) {
	if (*str == '#') {
		str++; return NULL;
	}
	//获取val的num值
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
	//如果是空，那么就返回#
	if (!root) return "#";
	//val值，连在一起
	string num = to_string(root->val);
	num.push_back(',');
	//先序遍历
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