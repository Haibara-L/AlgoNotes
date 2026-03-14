/*
题目：数组删除操作（最多两次）

问题描述：
给定一个长度为 n 的数组 a，每次操作可以删除一个所有元素都相等的连续子数组。
删除后，左右两部分自动拼接，相对顺序不变。
最多执行两次操作，求数组可能的最小长度。

解题思路：

1. 首先将原数组压缩成连续相等段，记录每段的值和长度。
   例如：[1,1,2,2,2,3,3,1,1] ->
   段值：[1,2,3,1]
   段长：[2,3,2,2]

2. 最多两次操作，所有可能的最优策略有三种情况：

   b) 操作两次，删除两个不相邻的段
      收益 = 最大的两个不相邻段长之和
      注意：如果最大段和次大段相邻，则不能取它们，需要找不相邻的

   c) 操作两次，利用删除后的合并效果：
      先删除一个段 i，如果它左右两边的段值相同，
      则它们会合并成一个新段（长度 = left_len + right_len），
      第二次操作删除这个新段
      总收益 = len[i] + len[i-1] + len[i+1]（要求左右值相等）

3. 最后答案 = n - max（ 情况b, 情况c)
*/




//#include <iostream>
//using namespace std;
//#include<vector>
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    vector<int> len;
//    vector<int> val;
//    int max1 = -1;
//    int max2 = -1;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> v[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (i == 0)
//        {
//            len.push_back(1);
//            val.push_back(v[0]);
//        }
//        else
//        {
//            if (v[i] == v[i - 1])
//            {
//                len[len.size() - 1]++;
//            }
//            else
//            {
//                if (len[len.size() - 1] > max1)
//                {
//                    max2 = max1;
//                    max1 = len[len.size() - 1];
//                }
//                else if (len[len.size() - 1] > max2)
//                {
//                    max2 = len[len.size() - 1];
//                }
//                len.push_back(1);
//                val.push_back(v[i]);
//            }
//        }
//    }
//    if (len[len.size() - 1] > max1)
//    {
//        max2 = max1;
//        max1 = len[len.size() - 1];
//    }
//    else if (len[len.size() - 1] > max2)
//    {
//        max2 = len[len.size() - 1];
//    }
//    int maxresult = max1 + max2;
//    for (int i = 0; i < len.size()-2; i++)
//    {
//        if (val[i] == val[i + 2])
//        {
//            maxresult = max(maxresult, len[i] + len[i + 1]+len[i + 2]);
//        }
//    }
//    maxresult = max(maxresult, len[len.size() - 2] + len[len.size() - 1]);
//    cout << n - maxresult << endl;
//    return 0;
//}