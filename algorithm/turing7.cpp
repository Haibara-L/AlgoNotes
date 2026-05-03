#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int T,K;
        cin>>K>>T;
        char c;
        int startrow,startcol;
        int endrow,endcol;
        vector<vector<int> > maze(K,vector<int>(K));
        vector<vector<int> > hasgone(K,vector<int>(K,0));
        for(int j=0;j<K;j++)
        {
            for(int k=0;k<K;k++)
            {
                cin>>c;
                if(c=='S')
                {
                    startrow=j;
                    startcol=k;
                    maze[j][k]=0;
                }
                else if(c=='E')
                {
                    endrow=j;
                    endcol=k;
                    maze[j][k]=0;
                }
                else if(c=='.')
                {
                    maze[j][k]=0;
                }
                else
                {
                    maze[j][k]=1;
                }
            }
        }
        queue<pair<pair<int,int>,int>> q;
        q.push(make_pair(make_pair(startrow,startcol),0));
        hasgone[startrow][startcol]=1;
        bool can=false;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p.second>T)
            {
                break;
            }
            if(p.first.first==endrow&&p.first.second==endcol)
            {
                can=true;
                break;
            }
            int x=p.first.first;
            int y=p.first.second;
            int time=p.second;
            int arr[3]={-1,0,1};
            for(int dx:arr)
            {
                for(int dy:arr)
                {
                    if(dx==0&&dy==0)
                    {
                        continue;
                    }
                    if(dx*dy!=0)
                    {
                        continue;
                    }
                    if(x+dx>=0&&x+dx<K&&y+dy>=0&&y+dy<K)
                    {
                        if(!maze[x+dx][y+dy]&&!hasgone[x+dx][y+dy])
                        {
                            q.push(make_pair(make_pair(x+dx,y+dy),time+1));
                            hasgone[x+dx][y+dy]=1;
                        }
                    }
                }
            }
        }
        if(can)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}