/*
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配



思路：这里改用DP方法。
*/

bool match(char* str, char* pattern) {
	int M = 0, N = 0;
	char * s = str, *p = pattern;
	//计算长度
	while (*(s++) != '\0') M++;
	while (*(p++) != '\0') N++;
	s = str; p = pattern;
	if (M == 0 && N == 0) return true;
	//创建DP值
	vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
	dp[0][0] = true;
	for (int i = 1; i < N + 1; i++) {
		//如果是*那么就跳过当前值，看前面一个值
		dp[0][i] = (i > 1) && (p[i - 1] == '*') && dp[0][i - 2];
	}
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (p[j - 1] != '*')
				//如果不是*,那么如果当前值比较成立，且各自去掉自己也成立，总得才成立
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			else {
				//如果是*，那么要么删除*和前面的内容看看是不是成立.
				//要么，如果*前面的值和str[i-1]的值相同，那么可以和dp[i-1][j]同等。
				//就是不包含当前对应的str[i-1].
				dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
			}
		}
	}
	return dp[M][N];
}