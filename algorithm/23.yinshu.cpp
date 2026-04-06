#include<iostream>
using namespace std;
#include<algorithm>

int main()
{
    int n;
    cin>>n;
    int num[100001]={0};
    int back[100001]={0};
    int front[100001]={0};
    for(int i=0;i<n;i++)
    {
        int number;
        cin>>number;
        num[number]++;
    }
    for(int i=1;i<=100000;i++)
    {
        if(num[i]==0)
        {
            continue;
        }
        int k=1;
        while(k*i<=100000)
        {
            if(num[k*i]==0)
            {
                ;
            }
            else
            {
                if(k==1)
                {
                    back[i]+=num[i]-1;
                    front[i]+=num[i]-1;
                }
                else
                {
                    back[i]+=num[k*i];
                    front[k*i]+=num[i];
                }
            }
            k++;
        }
    }
    long long total=0;
    long long exclude=0;
    for(int i=1;i<=100000;i++)
    {
        total+=num[i]*back[i];
        exclude+=num[i]*(front[i]+back[i])*(front[i]+back[i]-1);
    }
    total=total*(total-1)-exclude;
    cout<<total<<endl;
    return 0;

    
}