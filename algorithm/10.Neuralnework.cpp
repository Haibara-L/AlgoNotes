//Kahn算法：处理拓扑排序问题
// Kahn算法是一种基于入度的拓扑排序策略，
// 其核心在于不断提取图中所有入度为0的节点放入队列，
// 随后依次弹出这些节点并模拟删除其发出的所有边，
// 同时更新受影响邻居节点的入度，
// 一旦邻居入度减至0则立即入队，
// 以此循环直至队列为空，
// 从而排出一组满足先后依赖关系的线性序列；

//存储图的数据结构：邻接表
// 邻接表则是通过为每个节点建立一个动态增长的列表（如vector或链表）来存储其邻居信息，
// 这种“按需分配”的存储方式相比二维数组极大节省了空间开销，
// 且在Kahn算法执行过程中能通过直接访问列表来快速定位并更新邻居，
// 是处理大规模稀疏图竞赛题的标准配置。
// 例如可以使用vector<vector<pair<int,int>>>来记录或者使用结构体记录每一条边

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<climits>
int main()
{
    int n,p;
    cin>>n>>p;
    vector<int> status(n+1,0);
    vector<int> threshold(n+1,0);
    vector<int> indegree(n+1,0);
    vector<int> outdegree(n+1,0);
    queue<int> tpqueue;
    for(int i=0;i<n;i++)
    {
        cin>>status[i+1];
        cin>>threshold[i+1];
    }
    vector<vector<int>> neumap(n+1,vector<int>(n+1,INT_MAX));
    int x,y;
    for(int i=0;i<p;i++)
    {
        cin>>x>>y;
        cin>>neumap[x][y];
        indegree[y]++;
        outdegree[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            tpqueue.push(i);
        }
    }
    while(tpqueue.size()!=0)
    {
        int curNote=tpqueue.front();
        tpqueue.pop();
        for(int i=1;i<=n;i++)
        {
            if(neumap[curNote][i]!=INT_MAX)
            {
                if(status[curNote]>0)
                {
                    status[i]+=status[curNote]*neumap[curNote][i];
                }
                indegree[i]--;
                if(indegree[i]==0)
                {
                    tpqueue.push(i);
                    status[i]-=threshold[i];
                }
            }
        }
    }
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(outdegree[i]==0&&status[i]>0)
        {
            cout<<i<<' '<<status[i]<<endl;
            num++;
        }
    }
    if(num==0)
    {
        cout<<"NULL"<<endl;
    }
    return 0;
}
