#include<vector>
using namespace std;
#include<iostream>
#include<map>
#include<algorithm>
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> data;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(data.count(v[i])==0)
        {
            data.insert(make_pair(v[i],1));
        }
        else
        {
            data[v[i]]++;
        }
    }
    int totalnum=0;
    for(int i=1;i*i<=n-2;i++)
    {
        if((n-2)%i==0)
        {
            int j=(n-2)/i;
            vector<int>::iterator it1=find(v.begin(),v.end(),i);
            vector<int>::iterator it2=find(v.begin(),v.end(),j);
            if(it1!=v.end()&&it2!=v.end())
            {
                map<int,int> tempdata=data;
                tempdata[i]--;
                tempdata[j]--;
                int num=1;
                for(int k=1;k<=n-2;k++)
                {
                    num*=k;
                }
                for(auto it=tempdata.begin();it!=tempdata.end();it++)
                {
                    if(it->second!=0)
                    {
                        for(int k=1;k<=it->second;k++)
                        {
                            num/=k;
                        }
                    }
                }
                if(i*i!=n-2)
                {
                    num*=2;
                }
                totalnum=(totalnum+num)%1000000007;
            }
        }
    }
    cout<<totalnum<<endl;
    return 0;
}