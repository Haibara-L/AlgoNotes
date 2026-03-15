/*
问题描述：
小蓝的导师提供了 n 台机器人，第 i 台机器人需要充电 a_i 小时才能充满电。
机器人一旦充满电，就会立刻开始工作，并连续工作 b_i 小时，之后停止工作。

小蓝一次最多只能为一台机器人充电，并且每台机器人只能被充电一次。
小蓝可以自行决定这些机器人的充电顺序。
请你帮助小蓝规划一种充电顺序，使得所有机器人同时处于工作状态的时间尽可能长。

如果不存在任何时刻使得所有机器人同时工作，则答案为 0。

输入格式：
第一行包含一个整数 n (1 ≤ n ≤ 10^5)，表示机器人的数量。
第二行包含 n 个整数 a_1, a_2, ..., a_n (1 ≤ a_i ≤ 10^9)，表示每台机器人充满电所需的时间。
第三行包含 n 个整数 b_1, b_2, ..., b_n (1 ≤ b_i ≤ 10^9)，表示每台机器人充满电后可以持续工作的时间。

输出格式：
输出一个整数，表示在最优充电顺序下，所有机器人同时工作的最长时间。
如果不存在所有机器人同时工作的时刻，则输出 0。
*/
//解题思路：把最终的算式写出来就会发现其实就是初中绝对值加和找最小值的题目，只要找到中间的最低点就可以了
//
//
//
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//struct jm
//{
//	int height;
//	int cost;
//};
//bool compare(jm j1, jm j2)
//{
//	return j1.height < j2.height;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<jm> v(n);
//	int totalcost = 0;
//	int midid = 0;
//	int pre = 0;
//	int result = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i].height;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i].cost;
//		totalcost += v[i].cost;
//	}
//	sort(v.begin(), v.end(), compare);
//	if (totalcost % 2 == 0)
//	{
//		midid = totalcost / 2;
//	}
//	else
//	{
//		midid = totalcost / 2 + 1;
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (pre < midid && pre + v[i].cost >= midid)
//		{
//			midid = i;
//			break;
//		}
//		else
//		{
//			pre += v[i].cost;
//		}
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		result += abs(v[i].height - v[midid].height) * v[i].cost;
//	}
//	cout << result << endl;
//	return 0;
//
//}