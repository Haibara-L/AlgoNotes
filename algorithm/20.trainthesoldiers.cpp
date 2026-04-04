#include<iostream>
using namespace std;
#include<vector>

int main()
{
    long long snum;
    long long gmoney;
    cin>>snum>>gmoney;
    vector<int> traintimes(snum,0);
    vector<long long> needmoney(snum,0);
    for(int i=0;i<snum;i++)
    {
        cin>>needmoney[i]>>traintimes[i];
    }
    long long totalmoney=0;
    while(1)
    {
        int actualnum=0;
        int mintraintimes=1000000;
        for(int i=0;i<snum;i++)
        {
            if(traintimes[i]>0)
            {
                actualnum++;
                mintraintimes=min(mintraintimes,traintimes[i]);
            }
        }
        if(mintraintimes==1000000)
        {
            break;
        }
        long long sum=0;
        for(int i=0;i<snum;i++)
        {
            if(traintimes[i]!=0)
            {
                sum+=needmoney[i];
            }
        }
        if(gmoney<sum)
        {
            totalmoney+=gmoney*mintraintimes;
            for(int i=0;i<snum;i++)
            {
                if(traintimes[i]>0)
                {
                    traintimes[i]-=mintraintimes;
                }
            }
        }
        else
        {
            for(int i=0;i<snum;i++)
            {
                totalmoney+=traintimes[i]*needmoney[i];
            }
            break;
        }
    }
    cout<<totalmoney<<endl;
    return 0;


}