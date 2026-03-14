/*
题目：选积木求最大按位或值

问题描述：
有 n 个积木，编号 1 到 n，要选出恰好 k 个不同的积木，
使得它们的编号按位或的结果最大。

解题思路：

1. 按位或的性质：
   - 只要某一位上至少有一个数是 1，结果的这一位就是 1
   - 所以要让结果最大，就要让尽可能高的二进制位变成 1

2. 关键观察：
   如果 k = 1：直接取最大的数 n 即可
   如果k>=2,设二进制下最高的位数为n,那么只要一个取1000……，一个取0111……
*/


//#include<iostream>
//using namespace std;
//#include<vector>
//int main()
//{
//	int n;
//	int maxn,num;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> maxn >> num;
//		if (num == 1)
//		{
//			cout << maxn << endl;
//		}
//		else
//		{
//			int s = 0;
//			int result = 0;
//			while (maxn > 0)
//			{
//				maxn /= 2;
//				s++;
//			}
//			cout << ((1LL << s) - 1) << endl;
//		}
//	}
//	return 0;
//}
