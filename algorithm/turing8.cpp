#include<iostream>
using namespace std;
#include<cmath>
long long mod_inv(long long a, long long  m) {
    long long x, y, b = m;
    long long x1 = 1, x2 = 0;
    while (b) {
        long long q = a / b;
        long long r = a % b;
        long long x3 = x1 - q * x2;
        a = b; b = r;
        x1 = x2; x2 = x3;
    }
    if (a != 1) return -1;
    return (x1 % m + m) % m;
}
long long mmgcd(long long a,long long b)
{
    long long max=std::max(a,b);
    long long min=std::min(a,b);
    while(max%min!=0)
    {
        long long temp=min;
        min=max%min;
        max=temp;
    }
    return min;
}

int main()
{
    long long a,b,c,k;
    while(1)
    {
        cin>>a>>b>>c>>k;
        if(k==0)
        {
            break;
        }
        long long upper=1;
        for(int i=0;i<k;i++)
        {
            upper*=2;
        }
        if(c==0)
        {
            if(a==b)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<"FOREVER"<<endl;
            }
            continue;
        }
        long long mgdc=mmgcd(c,upper);
        if(abs(b-a)%mgdc!=0)
        {
            cout<<"FOREVER"<<endl;
        }
        else
        {
            long long a1=(a-b)/mgdc;
            long long d1=c/mgdc;
            long long m1=upper/mgdc;
            long long minv=mod_inv(d1,m1);
            long long step=(((-a1)*minv)%m1+m1)%m1;
            cout<<step<<endl;
        }
    }
    return 0;
}