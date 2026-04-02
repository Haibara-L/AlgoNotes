#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
    string s;
    cin>>s;
    vector<int> dp(s.size(),0);
    dp[0]=1;
    for(int i=1;i<s.size();i++)
    {
        dp[i]+=dp[i-1];
        if(s[i]==s[i-1]||s[i]==s[i-1]+1)
        {
            int j=i-1;
            int num=0;
            int pos1=-1,pos2=-1;
            while(j>0)
            {
                if(s[j]!=s[j-1]&&s[j]!=(s[j-1]+1))
                {
                    if(num==0)
                    {
                        num++;
                        pos2=j;
                    }
                    else if(num==1)
                    {
                        pos1=j;
                        break;
                    }
                }
                j--;
            }
            if(pos1==-1)
            {
                dp[i]+=i+1;
            }
            else 
            {
                dp[i]+=i-pos1+1;
            }
        }
        else
        {
            int j=i-1;
            int pos1=-1;
            while(j>0)
            {
                if(s[j]!=s[j-1]&&s[j]!=(s[j-1]+1))
                {
                    pos1=j;
                    break;
                }
                j--;
            }
            if(pos1==-1)
            {
                dp[i]+=i+1;
            }
            else 
            {
                dp[i]+=i-pos1+1;
            }
        }
    }
    cout<<dp[s.size()-1]<<endl;
    return 0;
}