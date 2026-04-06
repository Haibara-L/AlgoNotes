#include<iostream>
using namespace std;

int gcd(int smaller,int larger)
{
    while(larger%smaller!=0)
    {
        int temp=smaller;
        smaller=larger%smaller;
        larger=temp;
    }
    return smaller;
}

int main()
{
    int w,h;
    cin>>w>>h;
    int smaller,larger;
    if(w<h)
    {
        smaller=w;
        larger=h;
    }
    else
    {
        smaller=h;
        larger=w;
    }
    int mgcd=gcd(smaller,larger);
    if(mgcd==1)
    {
        cout<<0<<endl;
    }
    else
    {
        for(int i=2;i<=mgcd;i++)
        {
            if(mgcd%i==0)
            {
                long long x=w/i;
                long long y=h/i;
                cout<<x*y<<endl;
                break;
            }
        }
    }
    return 0;
}