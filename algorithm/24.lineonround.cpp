#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int> dp(2024,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=2023;i++)
    {
        dp[i]+=dp[i-1];
        dp[i]%=2023;
        for(int j=0;j<i-1;j++)
        {
            dp[i]+=dp[j]*dp[i-2-j];
            dp[i]%=2023;
        }
    }
    cout<<dp[2023]<<endl;
    return 0;
    
}