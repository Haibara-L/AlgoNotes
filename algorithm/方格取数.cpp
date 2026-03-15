//设有 N×N 的方格图 (N≤9)，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字 0:
//某人从图的左上角的 A 点出发，可以向下行走，也可以向右走，直到到达右下角的 B 点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 0）。
//此人从 A 点到 B 点共走两次，试找出 2 条这样的路径，使得取得的数之和为最大。

//输入格式
//输入的第一行为一个整数 N（表示 N×N 的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的 0 表示输入结束。

//输出格式
//只需输出一个整数，表示 2 条路径上取得的最大的和。


//解题思路：
//本题采用 双线程动态规划 ，核心思想是让两条路径 同时从(1, 1)出发，同步走到(n, n) 
// 状态 `dp[k][i][j]` 表示两条路径都走了 `k` 步时，第一条路径在第 `i` 行、第二条路径在第 `j` 行所能获得的最大数字和（列坐标可由 `k - i` 和 `k - j` 计算得出）。
// 对于每个状态，考虑两条路径上一步分别来自上方或左方的四种组合，取最大值后加上当前到达方格中的数字——若两条路径到达同一格子则只加一次，否则两个格子的值都加。
// 最终 `dp[2n - 1][n][n]` 即为两条路径能取到的最大总和。
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
//	int x, y, num;
//	while (cin >> x >> y >> num)
//	{
//		if (x == 0 && y == 0 && num == 0)
//		{
//			break;
//		}
//		v[x][y] = num;
//	}
//	if (n == 1)
//	{
//		cout << v[1][1] << endl;
//		return 0;
//	}
//	vector<vector<vector<int>>> st(2 * n + 1, vector <vector<int>>(n + 1, vector<int>(n + 1, 0)));
//	//st[0][1][1] = v[1][1];
//	for (int k = 1; k <= 2 * n; k++)
//	{
//		for (int r1 = 1; r1 <= min(k, n); r1++)
//		{
//			if (k - r1 + 1 > n)
//			{
//				continue;
//			}
//			for (int r2 = 1; r2 <= min(k, n); r2++)
//			{
//				int c1 = k - r1 + 1;
//				int c2 = k - r2 + 1;
//				if (c2 > n)
//				{
//					continue;
//				}
//				int val1 = st[k - 1][r1 - 1][r2 - 1];
//				int val2 = st[k - 1][r1][r2 - 1];
//				int val3 = st[k - 1][r1 - 1][r2];
//				int val4 = st[k - 1][r1][r2];
//				int val = max(max(val1, val2), max(val3, val4));
//				if (r1 == r2)
//				{
//					st[k][r1][r2] = val + v[r1][c1];
//				}
//				else
//				{
//					st[k][r1][r2] = val + v[r1][c1] + v[r2][c2];
//				}
//			}
//		}
//	}
//	cout << st[2 * n - 1][n][n] << endl;
//	return 0;
//}