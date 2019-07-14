/*
题目描述
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)



思路：这是一个最简单的DP问题。计算以i为结尾的最长数和dp[i]. 如果dp[i-1] 大于0，那么dp[i] = dp[i-1]+num[i]
	否则，dp[i] = num[i].然后返回最大值就可以。
*/

int FindGreatestSumOfSubArray(vector<int> array) {
	int n = array.size();
	if (n == 0) return 0;
	if (n == 1) return array[0];
	vector<int> dp(n, 0);
	dp[0] = array[0];
	int res = dp[0];
	//开始计算DP问题
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] < 0) dp[i] = array[i];
		else dp[i] = dp[i - 1] + array[i];
		res = max(res, dp[i]);//更新最大值
	}
	return res;
}