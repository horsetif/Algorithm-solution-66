/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)
中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.


思路：用set表示。如果第一次遍历到，那么就保存为1.如果再次遍历到，那么就保存为2.
最后再重新遍历一次，找到输出1的就退出。如果没有就返回-1.
*/

int FirstNotRepeatingChar(string str) {
	unordered_map<char, int> mp;
	for (auto c : str) {
		//查到了就为1，再次查到就为2
		if (mp.find(c) == mp.end()) mp[c] = 1;
		else mp[c] = 2;
	}
	//如果找到1就是i。
	for (int i = 0; i < str.size(); i++) {
		if (mp[str[i]] == 1) return i;
	}
	return -1;
}