#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>
using namespace std;

const int MAXN=500001;
int n;
int needcleaning[MAXN];
int degree[MAXN];
int value[MAXN];
vector<int> graph[MAXN];
bool is_on_cycle[MAXN]={true};

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>needcleaning[i];
        is_on_cycle[i]=true;
    }
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        degree[u-1]++;
        degree[v-1]++;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    queue<int> q;
    int max_on_tree=0;
    for(int i=0;i<n;i++)
    {
        value[i]=needcleaning[i];
        if(degree[i]==1)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        is_on_cycle[u]=false;
        for(int v:graph[u])
        {
            if(degree[v]>1)
            {
                max_on_tree=max(max_on_tree,value[u]+value[v]);
                value[v]=max(value[v],value[u]+needcleaning[v]);
                degree[v]--;
                if(degree[v]==1)
                {
                    q.push(v);
                }
            }
        }
    }
    int startid=0;
    vector<int> cycle;
    for(int i=0;i<n;i++)
    {
        if(is_on_cycle[i])
        {
            startid=i;
            break;
        }
    }
    int cur = startid;
    int pre = -1;
    while (true) 
    {
    cycle.push_back(cur);
    int next_node = -1;
    for (int v : graph[cur]) {
        // 必须在环上，且不能是上一个点，且不能在刚开始就跳回起点
        if (is_on_cycle[v] && v != pre) {
            if (v == startid && cycle.size() > 1) break; // 真正回到了起点
            if (v != startid) { next_node = v; break; }
        }
    }
    if (next_node == -1) break; 
    pre = cur; cur = next_node;
    }
    int m=cycle.size();
    vector<int> cyclevalue(2*m+1,0);
    vector<int> treevalue(2*m+1,0);
    for(int i=1;i<=2*m;i++)
    {
        cyclevalue[i]=cyclevalue[i-1]+needcleaning[cycle[(i-1)%m]];
        treevalue[i]=value[cycle[(i-1)%m]];
    }
    deque<int> d;
    int max_on_cycle=0;
    for(int j=1;j<=2*m;j++)
    {
        while(!d.empty()&&j-d.front()>=m)
        {
            d.pop_front();
        }
        if(!d.empty())
        {
            max_on_cycle=max(max_on_cycle,cyclevalue[j-1]+treevalue[j]+treevalue[d.front()]-cyclevalue[d.front()]);
        }
        while(!d.empty()&&(treevalue[d.back()]-cyclevalue[d.back()]<=treevalue[j]-cyclevalue[j]))
        {
            d.pop_back();
        }
        d.push_back(j);
    }
    cout<<max(max_on_cycle,max_on_tree)<<endl;
    return 0;
}