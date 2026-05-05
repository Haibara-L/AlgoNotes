#include<iostream>
using namespace std;
#include<vector>
#include<climits>
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(2*n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i+n]=v[i];
    }
    vector<int> pre(2*n);
    pre[0]=v[0];
    for(int i=1;i<2*n;i++)
    {
        pre[i]=pre[i-1]+v[i];
    }
    int max1=INT_MIN;
    int min1=INT_MAX;
    for(int start=0;start<n;start++)
    {
        vector<vector<int>> dpmin(n,vector<int>(m));
        vector<vector<int>> dpmax(n,vector<int>(m));
        for(int i=start;i<start+n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-start<j)
                {
                    break;
                }
                if(j==0)
                {
                    dpmin[i-start][j]=((pre[i]-(start==0?0:pre[start-1]))%10+10)%10;
                    dpmax[i-start][j]=((pre[i]-(start==0?0:pre[start-1]))%10+10)%10;
                    continue;
                }
                int mmax1=INT_MIN;
                int mmin1=INT_MAX;
                for(int k=i-1;k-start>=j-1;k--)
                {
                    mmax1=max(mmax1,(((pre[i]-pre[k])%10+10)%10)*dpmax[k-start][j-1]);
                    mmin1=min(mmin1,(((pre[i]-pre[k])%10+10)%10)*dpmin[k-start][j-1]);
                }
                dpmin[i-start][j]=mmin1;
                dpmax[i-start][j]=mmax1;
            }
        }
        max1=max(max1,dpmax[n-1][m-1]);
        min1=min(min1,dpmin[n-1][m-1]);
    }
    cout<<min1<<endl;
    cout<<max1<<endl;
    return 0;
} 
