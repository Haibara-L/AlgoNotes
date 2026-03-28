// Floyd 算法是一种基于动态规划的“全源最短路”算法，
// 其核心思想是通过三层循环，不断尝试以图中每一个点 k 作为中转站，去更新任意两点 i 与 j 之间的最短距离 dist[i][j]；
// 在场景选择上，Floyd 适用于点数较少（通常 N<500）且需要求解全图任意两点间距离的情况，即多源问题，代码极简但复杂度高达 O(N^3)，
// 而 Dijkstra 算法配合堆优化更适合处理大规模节点（如 N=10^5）的单源最短路问题（即固定起点到其他所有点），在稀疏图中效率远高于 Floyd。
//稀疏图多用邻接表，可以节省内存开销，而稠密图二者在内存占用上区别不大，但是二维数组简洁方便并且由于是连续存储，CPU访问更快，因此推荐使用二维数组
// 详细使用场景划分
// 什么时候“无脑”选 Floyd？
// 需求：你需要知道图中任意两点之间的距离（多源）。
// 特征：代码只有 4 行，点数 N 小于 500。
// 注意：如果 N=1000，Floyd 的 10^9 运算量通常会超时，这时候即使是多源需求，也要被迫跑 N 次 Dijkstra。
// 什么时候选 堆优化 Dijkstra？
// 需求：求一个起点到其他点的距离（单源）。
// 特征：点数特别多（10^5 级别），边数相对较少（稀疏图）。
// 优势：它是稀疏图的“王牌”，配合邻接表几乎能秒杀所有 10^5 级别的地图题。
// 什么时候选 普通 Dijkstra（不带堆）？
// 需求：单源最短路。特征：点不多（5000以内），但边极其多（稠密图）。
// 优势：在这种情况下，O(N^2) 的暴力 Dijkstra 比 O(Mlog N) 的堆优化 Dijkstra 跑得更稳，因为避开了堆操作的巨大常数开销。

// 竞赛中的终极优先级总结如果你在赛场上犹豫不决，请按以下优先级排序：
// 看点数 N：如果 N<500，优先用 Floyd。因为代码最短，不容易写错，还能处理各种奇怪的起终点组合。
// 看边数 M：如果 N 很大（>1000），必须用 Dijkstra。此时观察 M：如果 M 很大（接近 N^2），用普通版；如果 M 很小（接近 N），用堆优化版。


#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
#include<climits>
#include<cfloat>
#include<iomanip>
struct airport
{
    int id;
    int x;
    int y;
};

int main()
{
    int n,S,t,A,B;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>S>>t>>A>>B;
        vector<vector<double>> m_map(4*S,vector<double>(4*S,DBL_MAX));
        for(int i=0;i<4*S;i++)
        {
            m_map[i][i]=0;
        }
        vector<airport> v;
        for(int i = 0; i < S; i++) 
        {
            int x1, y1, x2, y2, x3, y3, x4, y4, T;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> T;
            long long d12 = (long long)(x1-x2)*(x1-x2) + (long long)(y1-y2)*(y1-y2);
            long long d13 = (long long)(x1-x3)*(x1-x3) + (long long)(y1-y3)*(y1-y3);
            long long d23 = (long long)(x2-x3)*(x2-x3) + (long long)(y2-y3)*(y2-y3);
            if (d12 + d13 == d23) 
            { 
        // 点1是直角顶点，2和3是对角线
                x4 = x2 + x3 - x1;
                y4 = y2 + y3 - y1;
            } 
            else if (d12 + d23 == d13) 
            { 
        // 点2是直角顶点，1和3是对角线
                x4 = x1 + x3 - x2;
                y4 = y1 + y3 - y2;
            } 
            else 
            { 
        // 点3是直角顶点，1和2是对角线
                x4 = x1 + x2 - x3;
                y4 = y1 + y2 - y3;
            }
            v.push_back(airport{4*i,x1,y1});
            v.push_back(airport{4*i+1,x2,y2});
            v.push_back(airport{4*i+2,x3,y3});
            v.push_back(airport{4*i+3,x4,y4});
            for(int x=0;x<4;x++)
            {
                for(int y=x+1;y<4;y++)
                {
                    double dist=sqrt(pow(v[4*i+x].x-v[4*i+y].x,2)+pow(v[4*i+x].y-v[4*i+y].y,2));
                    double cost=dist*T;
                    m_map[4*i+x][4*i+y]=cost;
                    m_map[4*i+y][4*i+x]=cost;
                }
            }
        }
        for(int i=0;i<S;i++)
        {
            for(int j=i+1;j<S;j++)
            {
                for(int x=0;x<4;x++)
                {
                    for(int y=0;y<4;y++)
                    {
                        double dist=sqrt(pow(v[4*i+x].x-v[4*j+y].x,2)+pow(v[4*i+x].y-v[4*j+y].y,2));
                        double cost=dist*t;
                        m_map[4*i+x][4*j+y]=cost;
                        m_map[4*j+y][4*i+x]=cost;
                    }
                }
            }
        }
        for(int u=0;u<4*S;u++)
        {
            for(int i=0;i<4*S;i++)
            {
                for(int j=0;j<4*S;j++)
                {
                    m_map[i][j]=min(m_map[i][j],m_map[i][u]+m_map[u][j]);
                }
            }
        }
        double mincost=DBL_MAX;
        A--;
        B--;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                mincost=min(mincost,m_map[4*A+i][4*B+j]);
            }
        }
        cout<<fixed<<setprecision(1)<<mincost<<endl;
    }
    return 0;
}

