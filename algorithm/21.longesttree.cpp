#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<map>
int n,m;
vector<int> tree1Node;
vector<int> tree2Node;
vector<int> tree1[200001];
vector<int> tree2[200001];
int dfs(int prenode1,int prenode2,int curnode1,int curnode2)
{
    bool flag=false;
    int childmax=0;
    if(tree1Node[curnode1]!=tree2Node[curnode2])
    {
        return 0;
    }
    map<int,int> m;
    set<int> s;
    for(int i:tree1[curnode1])
    {
        if(i==prenode1)
        {
            continue;
        }
        m.insert(make_pair(tree1Node[i],i));
        s.insert(tree1Node[i]);
    }
    for(int i:tree2[curnode2])
    {
        if(i==prenode2)
        {
            continue;
        }
        auto j=s.find(tree2Node[i]);
        if(j!=s.end()&&m[*j]!=prenode1)
        {
            childmax=max(childmax,dfs(curnode1,curnode2,m[*j],i));
        }
    }
    return childmax+1;
}
int main()
{ 
    cin>>n>>m;
    tree1Node.resize(n,0);
    tree2Node.resize(m,0);
    for(int i=0;i<n;i++)
    {
        cin>>tree1Node[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>tree2Node[i];
    }
    
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree1[u-1].push_back(v-1);
        tree1[v-1].push_back(u-1);
    }
    for(int i=0;i<m-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree2[u-1].push_back(v-1);
        tree2[v-1].push_back(u-1);
    }
    int prenode1=-1;
    int prenode2=-1;
    int curnode1=0;
    int curnode2=0;
    int maxnum=0;
    cout<<dfs(prenode1,prenode2,curnode1,curnode2)<<endl;
    return 0;
}