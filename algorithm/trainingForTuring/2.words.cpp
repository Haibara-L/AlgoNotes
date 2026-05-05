#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
int main()
{
    int rows,k;
    cin>>rows>>k;
    string s;
    string mstr;
    for(int i=0;i<rows;i++)
    {
        cin>>mstr;
        s+=mstr;
    }
    vector<string> mdict;
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>mstr;
        mdict.push_back(mstr);
    }
    int len=s.size();
    vector<vector<int>> sum(len,vector<int>(len));
    for(int j=0;j<len;j++)
    {
        for(int i=j;i>=0;i--)
        {
            if(i==j)
            {
                if(find(mdict.begin(),mdict.end(),s.substr(i,1))!=mdict.end())
                {
                    sum[i][j]=1;
                }
                else
                {
                    sum[i][j]=0;
                }
            }
            else
            {
                int mmax=0;
                for(string ms:mdict)
                {
                    if(ms.size()<=j-i+1&&s.compare(i,ms.size(),ms)==0)
                    {
                        mmax=1;
                        break;
                    }
                }
                sum[i][j]=mmax+sum[i+1][j];
            }
        }
    }
    vector<vector<int>> dp(len,vector<int>(k,0));
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i<j)
            {
                break;
            }
            if(j==0)
            {
                dp[i][0]=sum[0][i];
                continue;
            }
            for(int t=i-1;t>=j-1;t--)
            {
                dp[i][j]=max(dp[i][j],dp[t][j-1]+sum[t+1][i]);
            }
        }
    }
    cout<<dp[len-1][k-1]<<endl;
    return 0;

}