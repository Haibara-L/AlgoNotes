#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int n;
    vector<int> v;
    while(cin>>n)
    {
        v.push_back(n);
    }
    vector<int> d1;
    for(int i=0;i<v.size();i++)
    {
        if(i==0)
        {
            d1.push_back(v[0]);
            continue;
        }
        if(v[i]<=d1[d1.size()-1])
        {
            d1.push_back(v[i]);
            continue;
        }
        int left=0;
        int right=d1.size()-1;
        int pos=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(d1[mid]>=v[i])
            {
                left=mid+1;
            }
            else
            {
                pos=mid;
                right=mid-1;
            }
        }
        d1[pos]=v[i];
    }
    vector<int> d2;
    for(int i=0;i<v.size();i++)
    {
        if(i==0)
        {
            d2.push_back(v[0]);
            continue;
        }
        if(v[i]>d2[d2.size()-1])
        {
            d2.push_back(v[i]);
            continue;
        }
        int left=0;
        int right=d2.size()-1;
        int pos=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(d2[mid]<=v[i])
            {
                left=mid+1;
            }
            else
            {
                pos=mid;
                right=mid-1;
            }
        }
        d2[pos]=v[i];
    }
    cout<<d1.size()<<endl;
    cout<<d2.size()<<endl;
    return 0;

}