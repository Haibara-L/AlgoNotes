#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        long long l,r;
        cin>>l>>r;
        if(2*l>r)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<(r-2*l+2)*(r-2*l+1)/2<<endl;
        }
    }
    return 0;
    
}