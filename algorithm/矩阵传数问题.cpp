//帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的 n×m 的矩阵，矩阵中的每个元素 a
//i, j?
//均为非负整数。游戏规则如下：
//每次取数时须从每行各取走一个元素，共 n 个。经过 m 次后取完矩阵内所有元素；
//每次取走的各个元素只能是该元素所在行的行首或行尾；
//每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值 ×2
//i
//，其中 i 表示第 i 次取数（从 1 开始编号）；
//游戏结束总得分为 m 次取数得分之和。
//帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。
//
//解题思路：
//逐行独立处理、区间动态规划** 的思路来解决矩阵取数问题：
//对于每一行，定义 `dp[start][end]` 表示当前行剩余区间为 `[start, end]` 时能获得的最大得分，
//通过** 区间长度从小到大** 进行递推（用变量 `Step` 控制区间长度减一），
//每次决策取区间左端或右端的元素，并根据** 已取走的元素个数** （即 `m - 当前区间长度`）确定当前取数是第几次，从而计算该元素对得分的贡献（元素值乘以 2 的对应次方），
//最终将每行 `dp[1][m]` 的结果累加得到总最大得分。

//#include<iostream>
//using namespace std;
//#include<vector>
//#include<cmath>
//#include<algorithm>
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> v(m+1,0);
//	long long result = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 1 ;j <= m; j++)
//		{
//			cin >> v[j];
//		}
//		vector<vector<long long>> dp(m + 1, vector<long long>(m + 1, 0));
//		for (int Step = 0; Step <= m - 1; Step++)
//		{
//			for (int start = 1; start + Step <= m; start++)
//			{
//				int end = start + Step;
//				int startpow = m - Step;
//				if (Step == 0)
//				{
//					dp[start][end] = v[start] * pow(2, startpow);
//				}
//				else
//				{
//					dp[start][end] = max((dp[start + 1][end] + v[start] * pow(2, startpow)), (dp[start][end - 1] + v[end] * pow(2, startpow)));
//				}
//			}
//		}
//		result += dp[1][m];
//	}
//	cout << result << endl;
//}