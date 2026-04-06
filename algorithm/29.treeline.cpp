#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct edge
{
    int to;
    int from;
    long long weight;
    bool operator==(const edge& e)
    {
        if(e.to==to&&e.from==from)
        {
            return true;
        }
        else if(e.from==to&&e.to==from)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
bool compare(edge e1,edge e2)
{
    return e1.weight>e2.weight;
}

vector<edge> tree[200005];
int degree[200005]={0};
vector<edge> lines;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int from=i+2;
        int to;
        long long weight;
        cin>>to>>weight;
        tree[from].push_back(edge{to,from,weight});
        tree[to].push_back(edge{from,to,weight});
        degree[from]++;
        degree[to]++;
        lines.push_back(edge{from,to,weight});
    }
    long long maxweight=0;
    //中心三线
    for(int i=1;i<=n;i++)
    {
        sort(tree[i].begin(),tree[i].end(),compare);
    }
    for(int i=1;i<=n;i++)
    {
        if(degree[i]>=3)
        {
            maxweight=max(maxweight,tree[i][0].weight+tree[i][1].weight+tree[i][2].weight);
        }
    }
    for(edge e:lines)
    {
        if(degree[e.from]>=2&&degree[e.to]>=2)
        {
            long long max1,max2;
            if(tree[e.from][0]==e)
            {
                max1=tree[e.from][1].weight;
            }
            else
            {
                max1=tree[e.from][0].weight;
            }
            if(tree[e.to][0]==e)
            {
                max2=tree[e.to][1].weight;
            }
            else
            {
                max2=tree[e.to][0].weight;
            }
            maxweight=max(maxweight,e.weight+max1+max2);
        }
    }
    cout<<maxweight<<endl;
    return 0;
}
