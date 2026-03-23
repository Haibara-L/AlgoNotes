/*
题目来源：P1052 [NOIP 2005 提高组] 过河

题目描述：
有一条长度为 L 的独木桥，青蛙从坐标 0 出发，要到达或越过坐标 L。
青蛙每次跳跃的距离可以取 [S, T] 之间的任意正整数（S ≤ T）。
桥上某些位置有石子（由输入给出，起点和终点没有石子）。
青蛙希望尽量减少踩到石子的次数，求最少需要踩到的石子数。

数据范围：
L 最大可达 10^9，M ≤ 100，1 ≤ S ≤ T ≤ 10。

解题思路：
1. 问题本质：
   这是一个典型的“动态规划 + 路径压缩”问题。
   如果直接用 DP 从 0 到 L 计算，L 太大无法承受（10^9 的数组太大）。

2. 观察与优化：
   - 石子数量 M 很小（最多 100），而 L 很大。
   - 青蛙的跳跃能力有限（S, T ≤ 10），意味着在两个石子之间的“大段空地区域”中，青蛙的跳跃模式是周期性的。
   - 因此，我们可以将两个石子之间的距离压缩到一个合理的范围内，而不会影响答案的正确性。

3. 压缩原理：
   - 设两个石子之间的距离为 d。
   - 当 d 足够大时（通常取 d > T*(T+1) 或 d > 100），后面的可到达位置会形成“连续区间”，再增加距离不会产生新的可达状态。
   - 因此，对于任意 d > MAX_DIST，我们都可以将其视为 MAX_DIST 来处理。
   - 这样，整个桥的长度从 L 被压缩到约 (M+2) * MAX_DIST 的量级（约 11000），完全可做 DP。

4. 特殊处理：
   - 当 S == T 时，青蛙每次只能跳固定步长，此时只需要检查石子位置是否能被 S 整除即可，不需要压缩和 DP。

5. 算法步骤：
   a. 读入 L, S, T, M 和石子位置数组。
   b. 如果 S == T，直接统计所有能被 S 整除的石子个数作为答案。
   c. 否则，将起点 0 和终点 L 也加入石子位置列表，然后排序。
   d. 遍历相邻点，计算距离，若距离 > MAX_DIST（取 100 或 T*(T+1)），则截断为 MAX_DIST。
   e. 累加得到新坐标序列 new_pos，新桥长 new_len = new_pos.back()。
   f. 标记新坐标中的石子位置（原石子对应 new_pos 中的位置）。
   g. 在新长度 new_len + T 的范围内做 DP：
        dp[i] 表示到达位置 i 时踩到的最少石子数。
        转移：dp[i] = min(dp[i - step] + (i 处是否有石子 ? 1 : 0))，step 从 S 到 T。
   h. 答案取 dp[new_len] 到 dp[new_len + T - 1] 中的最小值（因为可以跳过终点）。

6. 时间复杂度：
   O((M * MAX_DIST) * (T - S + 1))，约 10^4 * 10，完全可以接受。

7. 注意事项：
   - 压缩时起点和终点都要参与，保证所有长距离都被压缩。
   - DP 数组要开足够大，覆盖终点之后 T 步的范围，确保能跳到或超过终点。
   - 当 S == T 时，直接计算，避免压缩逻辑导致结果错误。
*/


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#define MAXDISTANCE 200
int main()
{
    int len,minstep,maxstep,stonenum;
    cin>>len>>minstep>>maxstep>>stonenum;
    vector<int> stones(stonenum,0);
    for(int i=0;i<stonenum;i++)
    {
        cin>>stones[i];
    }
    sort(stones.begin(),stones.end());
    if(minstep==maxstep)
    {
        int num=0;
        for(int i=0;i<stonenum;i++)
        {
            if(stones[i]%minstep==0)
            {
                num++;
            }
        }
        cout<<num<<endl;
        return 0;
    }
    if(stones[0]>MAXDISTANCE)
    {
        int redu=stones[0]-MAXDISTANCE;
        len-=redu;
        for(int i=0;i<stonenum;i++)
        {
            stones[i]-=redu;
        }
    }
    for(int i=1;i<stonenum;i++)
    {
        if(stones[i]-stones[i-1]>MAXDISTANCE)
        {
            int redu=stones[i]-stones[i-1]-MAXDISTANCE;
            len-=redu;
            for(int j=i;j<stonenum;j++)
            {
                stones[j]-=redu;
            }
        }
    }
    if(len-stones[stones.size()-1]>MAXDISTANCE)
    {
        len=stones[stones.size()-1]+MAXDISTANCE;
    }
    vector<int> bridge(len+maxstep,0);
    for(int i=0;i<stonenum;i++)
    {
        bridge[stones[i]]=1;
    }
    vector<int> dp(len+maxstep,stonenum+1);
    dp[0]=0;
    for(int i=1;i<len+maxstep;i++)
    {
        for(int j=minstep;j<=maxstep;j++)
        {
            if(i-j>=0)
            {
                if(dp[i-j]<=stonenum)
                {
                    dp[i]=min(dp[i-j]+bridge[i],dp[i]);
                }
            }
            else
            {
                break;
            }
        }
    }
    int minstones=stonenum+1;
    for(int i=len;i<len+maxstep;i++)
    {
        minstones=min(minstones,dp[i]);
    }
    cout<<minstones<<endl;
    return 0;
}