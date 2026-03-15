//小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。一次素质拓展活动中，班上同学安排坐成一个 m 行 n 列的矩阵，
//而小渊和小轩被安排在矩阵对角线的两端，因此，他们就无法直接交谈了。幸运的是，他们可以通过传纸条来进行交流。纸条要经由许多同学传到对方手里，小渊坐在矩阵的左上角，坐标(1, 1)，小轩坐在矩阵的右下角，坐标(m, n)。
//从小渊传到小轩的纸条只可以向下或者向右传递，从小轩传给小渊的纸条只可以向上或者向左传递。
//在活动进行中，小渊希望给小轩传递一张纸条，同时希望小轩给他回复。班里每个同学都可以帮他们传递，但只会帮他们一次，也就是说如果此人在小渊递给小轩纸条的时候帮忙，那么在小轩递给小渊的时候就不会再帮忙。反之亦然。
//还有一件事情需要注意，全班每个同学愿意帮忙的好感度有高有低（注意：小渊和小轩的好心程度没有定义，输入时用 0 表示），可以用一个[0, 100] 内的自然数来表示，数越大表示越好心。
//小渊和小轩希望尽可能找好心程度高的同学来帮忙传纸条，即找到来回两条传递路径，使得这两条路径上同学的好心程度之和最大。现在，请你帮助小渊和小轩找到这样的两条路径。
//解题思路：这道题的思路和方格取数那道题类似，注意到正向走和反向走效果相同，因此可以看成两条路同时从正向出发，使用三维数组维护
//#include<iostream>
//using namespace std;
//#include<vector>
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<vector<int>> route(m + 1, vector<int>(n + 1,0));
//	vector<vector<vector<int>>> dp(m + n - 1, vector<vector<int>>(m + 1, vector<int>(m + 1,0)));
//	for(int i=1;i<=m;i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> route[i][j];
//		}
//	}
//	for (int step = 1; step <= m + n - 2; step++)
//	{
//		for (int r1 = 1; r1 <= m; r1++)
//		{
//			if (step - r1 + 2 > n||step-r1+2<0)
//			{
//				continue;
//			}
//			for (int r2 = 1; r2 <= m; r2++)
//			{
//				int c1 = step - r1 + 2;
//				int c2 = step - r2 + 2;
//				if (c2 > n||c2<0)
//				{
//					continue;
//				}
//				int val1 = dp[step - 1][r1 - 1][r2 - 1];
//				int val2 = dp[step - 1][r1][r2 - 1];
//				int val3 = dp[step - 1][r1 - 1][r2];
//				int val4 = dp[step - 1][r1][r2];
//				int val = max(max(val1, val2), max(val3, val4));
//				if (r1 == r2)
//				{
//					dp[step][r1][r2] = val + route[r1][c1];
//				}
//				else
//				{
//					dp[step][r1][r2] = val + route[r1][c1] + route[r2][c2];
//				}
//								
//			}
//		}
//	}
//	cout << dp[m + n - 2][m][m] << endl;
//	return 0;
//}